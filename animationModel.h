#pragma once

#include<unordered_map>

#include"assimp/cimport.h"
#include"assimp/scene.h"
#include"assimp/postprocess.h"
#include"assimp/matrix4x4.h"
#pragma comment(lib,"assimp.lib")


// �ό`�㒸�_�\���́A�꒸�_���̃f�[�^�B�X�L�����b�V���̕��B���ɂ��Ă���B
struct DEFORM_VERTEX
{
	aiVector3D	Position;
	aiVector3D	Normal;
	int			BoneNum;
	// �x�̍��ɂ������Ă��邩�̃f�[�^�B�ő�S�{�̍��̃f�[�^�����Ă�悤�ɂ��Ă�
	std::string BoneName[4];	// �{���̓{�[���C���f�b�N�X�ŊǗ����ׂ�
	float		BoneWeight[4];	// ���̍��ɂǂ̂��炢�̊����ł������Ă��邩
};

// �{�[���\���́A��{���̍���\���Ă���
struct BONE
{
	aiMatrix4x4 Matrix;
	aiMatrix4x4 AnimationMatrix;
	aiMatrix4x4 OffsetMatrix;
};


class AnimationModel
{

private:
	const aiScene* m_AiScene = NULL;
	std::unordered_map <std::string, const aiScene*> m_Animation;
	ID3D11Buffer** m_VertexBuffer;
	ID3D11Buffer** m_IndexBuffer;

	std::unordered_map<std::string,
		ID3D11ShaderResourceView*> m_Texture;

	std::vector<DEFORM_VERTEX>* m_DeformVertex;	// �ό`�㒸�_�f�[�^
	std::unordered_map<std::string, BONE> m_Bone; // �{�[���f�[�^(���O�ŎQ��)

	void CreateBone(aiNode* node);
	void UpdateBoneMatrix(aiNode* node, aiMatrix4x4 matrix);

public:

	void Load(const char* fileName);
	void LoadAnimation(const char* fileName, const char* AnimationName);

	void Unload();
	void Update(const char* AnimationName, int Frame);
	void Draw();

};
