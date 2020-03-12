#pragma once
#include "Framework/GameObject.h"
class Mushroom : public GameObject
{
private:


public:
	Mushroom();
	~Mushroom();

	void update(float dt) override;
};

