#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1), move_(XMFLOAT3(0, 0, 0))
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	Collider* collider = new SphereCollider({ 0,0,0 }, 0.25f);
	AddCollider(collider);
}

void Bullet::Update()
{
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	move_.y -= 0.005f;
	XMVECTOR vMove = XMLoadFloat3(&move_);

	vPos = vPos + vMove;

	XMStoreFloat3(&transform_.position_, vPos);
	if (transform_.position_.y < -50.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		KillMe();
	}
}
