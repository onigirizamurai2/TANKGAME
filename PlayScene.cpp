#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
//#include "TankHead.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "playScene")
{
}

void PlayScene::Initialize()
{
	Instantiate <Ground>(this);
	Instantiate <Tank>(this);
	//Instantiate <TankHead>(this);

	GameObject* pTank = FindObject("Tank");
	XMFLOAT3 tankPos = { 0.0f, 0.0f, 0.0f };
	if (pTank != nullptr)
	{
		tankPos = pTank->GetPosition();
	}

	const int ENEMY_COUNT = 5;
	for (int i = 0; i < ENEMY_COUNT; ++i)
	{
		Enemy* newEnemy = Instantiate<Enemy>(this);
		XMFLOAT3 spawnPos;
		float distanceSq = 0.0f;

		do {
			float x = ((float)rand() / RAND_MAX) * 30.0f - 15.0f;
			float z = ((float)rand() / RAND_MAX) * 30.0f - 15.0f;
			spawnPos = { x, 0.0f, z };

			float dx = spawnPos.x - tankPos.x;
			float dz = spawnPos.z - tankPos.z;
			distanceSq = dx * dx + dz * dz;

		} while (distanceSq < 9.0f);

		newEnemy->SetPosition(spawnPos);
	}
}

void PlayScene::Update()
{
	Collision(this);
	Collision(this);
	Collision(this);
	Collision(this);
	Collision(this);
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
