#pragma once
#include"GameObject.h"

class Player : public GameObject //継承
{

private:

	/*D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;*/

	//Model* m_Model;
	class AnimationModel* m_Model;

	ID3D11VertexShader* m_VertexShader;
	ID3D11PixelShader*	m_PixelShader;
	ID3D11InputLayout*	m_VertexLayout;

	int					m_Frame;
	std::string			m_AnimationName;

public:

	//override スペルミスとか、ミス防止のためにつける
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
};

