#pragma once
#include "Engine/GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet(GameObject* parent);
	~Bullet() {}

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
	void OnCollision(GameObject* pTarget) override;
	void SetMoveVecter(XMFLOAT3 move) { move_ = move; }//弾の進行方向をセット
private:
	int hModel_;
	XMFLOAT3 move_;//弾の進行方向
};
