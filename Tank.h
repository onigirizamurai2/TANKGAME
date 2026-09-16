#pragma once
#include "Engine/GameObject.h"

class Tank :
    public GameObject
{
public:
	Tank(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
private:
	int hModel_;
	int camType_;
	void SetFixedCam();
};

