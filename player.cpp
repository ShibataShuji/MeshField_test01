#include "main.h"
#include "renderer.h"
#include "model.h"
#include "input.h"
#include "animationModel.h"
#include "player.h"
#include "MeshField.h"
#include "manager.h"
#include "scene.h"


void Player::Init()
{

	m_Model = new AnimationModel();
	m_Model->Load("asset\\model\\Akai_Idle.fbx");
	//m_Model->LoadAnimation("asset\\model\\Akai_Idle.fbx", "Idle");
	m_Model->LoadAnimation("asset\\model\\Akai_Idle.fbx", "Idle");
	m_Model->LoadAnimation("asset\\model\\Akai_Run.fbx", "Run");
	m_AnimationName = "Idle";

	m_Position = D3DXVECTOR3(0.0f, 1.0f, -3.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(0.01f, 0.01f, 0.01f);

	Renderer::CreateVertexShader(&m_VertexShader,&m_VertexLayout,"vertexLightingVS.cso");

	Renderer::CreatePixelShader(&m_PixelShader, "vertexLightingPS.cso");

	m_Frame = 0;

}

void Player::Uninit()
{
	m_Model->Unload();
	delete m_Model;

	m_VertexLayout->Release();
	m_VertexShader->Release();
	m_PixelShader->Release();

}

void Player::Update()
{
	if (Input::GetKeyPress('W'))
	{
		m_AnimationName = "Run";
	}
	else
	{
		m_AnimationName = "Idle";
	}



	//回転
	if (Input::GetKeyPress('Q'))
	{
		m_Rotation.x -= 0.1f;
	}
	if (Input::GetKeyPress('E'))
	{
		m_Rotation.x += 0.1f;
	}
	//左右
	D3DXVECTOR3 right = GetRight();

	if (Input::GetKeyPress('A'))
	{
		m_Position -= right * 0.1f;
	}
	if (Input::GetKeyPress('D'))
	{
		m_Position += right * 0.1f;
	}

	//上下

	D3DXVECTOR3 forward = GetForward();

	if (Input::GetKeyPress('W'))
	{
		m_Position -= forward * 0.1f;
	}
	if (Input::GetKeyPress('S'))
	{
		m_Position += forward * 0.1f;
	}

	int gggrgrg = 56;
	// メッシュフィールド高さ取得
	MeshField* meshField = Manager::GetScene()->GetGameObject<MeshField>(1);
	float meshHeight = meshField->GetHeight(m_Position);

	if (m_Position.y < meshHeight)
		m_Position.y = meshHeight;
	else
		m_Position.y -= 0.02f;

	m_Frame++;
}

void Player::Draw()
{
	m_Model->Update(m_AnimationName.c_str(), m_Frame);

	// 入力レイアウト設定
	Renderer::GetDeviceContext()->IASetInputLayout(m_VertexLayout);

	//シェーダ設定
	Renderer::GetDeviceContext()->VSSetShader(m_VertexShader, NULL, 0);
	Renderer::GetDeviceContext()->PSSetShader(m_PixelShader, NULL, 0);

	//ワールドマトリックス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.x, m_Rotation.y, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);
	world = scale * rot * trans;


	Renderer::SetWorldMatrix(&world);


	m_Model->Draw();
}