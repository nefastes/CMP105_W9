#pragma once
#include "Framework/GameObject.h"
class Missile : public GameObject
{
private:


public:
	Missile();
	~Missile();

	void update(float dt) override;
};

