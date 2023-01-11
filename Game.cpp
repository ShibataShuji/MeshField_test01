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


	// ���ԑ厖�` ���߂�A�R�����Ԃ����A�Q�����Ԃ���e
	AddGameObject<Camera>(0);

	for (int i = 0; i < 16; i++)
	{
		AddGameObject<MeshField>(1);

	}

	AddGameObject<Player>(1);



	AddGameObject<Polygon2D>(2);
	// 2D�̌�ɂ�3D�͕\���ł��Ȃ��G�G


}

void Game::Uninit()
{
	Scene::Uninit();		// �p�����̃N���X�̃��\�b�h�Ăяo��
}

void Game::Update()
{
	Scene::Update();


}