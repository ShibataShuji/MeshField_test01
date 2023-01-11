#pragma once
#include "GameObject.h"
#include "renderer.h"

static const int	FieldSize = 1024;
static const float PanelSize = 0.1f;

class MeshField : public GameObject
{
private:

	ID3D11Buffer*				m_VertexBuffer = NULL;
	ID3D11Buffer*				m_IndexBuffer = NULL;
	ID3D11ShaderResourceView*	m_Texture = NULL;

	VERTEX_3D					m_Vertex[FieldSize + 1][FieldSize + 1];

	ID3D11VertexShader*			m_VertexShader = NULL;
	ID3D11PixelShader*			m_PixelShader = NULL;
	ID3D11InputLayout*			m_VertexLayout = NULL;

public:

	void Init();
	void Uninit();
	void Update();
	void Draw();

	float GetHeight(D3DXVECTOR3 Position);
};

