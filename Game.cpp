#include <random>
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"


#include "camera.h"
#include "field.h"
#include "MeshField.h"
#include "model.h"
#include "player.h"
#include "field.h"
#include "polygon2D.h"
#include "Game.h"


void Game::Init()
{


	// 順番大事～ かめら、３ｄおぶじぇ、２ｄおぶじぇe
	AddGameObject<Camera>(0);

	for (int i = 0; i < 16; i++)
	{
		AddGameObject<MeshField>(1);

	}

	AddGameObject<Player>(1);



	AddGameObject<Polygon2D>(2);
	// 2Dの後には3Dは表示できない；；


}

void Game::Uninit()
{
	Scene::Uninit();		// 継承元のクラスのメソッド呼び出し
}

void Game::Update()
{
	Scene::Update();


}