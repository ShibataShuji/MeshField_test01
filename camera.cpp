#include "main.h"
#include "manager.h"
#include "scene.h"
#include "renderer.h"
#include "camera.h"
#include "player.h"

void Camera::Init()
{
	m_Position = D3DXVECTOR3(0.0f,4.0f,-6.0f);
	m_Target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

void Camera::Uninit() 
{

}

void Camera::Update() 
{
	// プレイヤーのビューマトリクス取得
	Scene* scene = Manager::GetScene();
	Player* player = scene->GetGameObject<Player>(1);
	D3DXVECTOR3 PlayerPosition = player->GetPosition();
	D3DXVECTOR3 PlayerForward = player->GetForward();

	//// トップビュー
	//m_Target = PlayerPosition;
	//m_Position = PlayerPosition + D3DXVECTOR3(0.0f, 2.0f, -5.0f);

	// サードパーソンビュー
	m_Target = PlayerPosition;
	m_Position = PlayerPosition - PlayerForward * 5.0f + D3DXVECTOR3(0.0f, 2.0f, 0.0f);

	//// ファーストパーソンビュー
	//m_Target = PlayerPosition + PlayerForward;
	//m_Position = PlayerPosition;

}
void Camera::Draw() 
{

	//ビューマトリックス設定
	D3DXMATRIX viewMatrix;
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&viewMatrix, &m_Position, &m_Target, &up);

	Renderer::SetViewMatrix(&viewMatrix);

	//プロジェクションマトリックス設定
	D3DXMATRIX projectionMatrix;
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, 1.0f,
		(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);

	Renderer::SetProjectionMatrix(&projectionMatrix);

}
