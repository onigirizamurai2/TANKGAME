#include "TankHead.h"
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

TankHead::TankHead(GameObject* parent)
	: GameObject(parent, "TankHead"),hModel_(-1)
{
}

void TankHead::Initialize()
{
	//モデルの読み込み、データの用意
	hModel_ = Model::Load("Tankhead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		//タンクヘッドの回転
		transform_.rotate_.y -= 1.0f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		//タンクヘッドの回転
		transform_.rotate_.y += 1.0f;
	}

	if (Input::IsKeyDown(DIK_SPACE))  
	{
		const float BULL_SPEED = 0.2f;
		XMFLOAT3 cannonTop = Model::GetBonePosition(hModel_, "Top");
		XMFLOAT3 cannonRoot = Model::GetBonePosition(hModel_, "Root");
		XMVECTOR vTop = XMLoadFloat3(&cannonTop);
		XMVECTOR vRoot = XMLoadFloat3(&cannonRoot);
		XMVECTOR vMove = XMVectorSubtract(vTop, vRoot);
		//XMVECTOR vMove = vTop - vRoot;
		vMove = 0.2f* vMove;
		XMFLOAT3 move;
		XMStoreFloat3(&move, vMove);
		//弾を生成する
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->SetMoveVecter(move);
		pBullet->SetPosition(cannonTop);
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
