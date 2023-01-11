#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "polygon2D.h"
#include "Field.h"
#include "camera.h"
#include "model.h"
#include "player.h"
#include "scene.h"
#include "Game.h"


Scene* Manager::m_Scene = NULL;			// これは.hの方のやつで書いたようにもっかい呼ばなきゃいけないから、
									// SceneクラスのポインタのManagerクラスのメンバ変数m_Sceneをセットしている。


void Manager::Init()
{
	Renderer::Init();
	Input::Init();

	SetScene<Game>();

}


void Manager::Uninit()
{

	m_Scene->Uninit();
	delete m_Scene;

	Input::Uninit();
	Renderer::Uninit();
}

void Manager::Update()
{
	Input::Update();


	m_Scene->Update();
}

void Manager::Draw()
{
	Renderer::Begin();

	m_Scene->Draw();

	Renderer::End();// カメラは先！呼び出し順大時// 3D空間での表示// UI系は最後に。

}
