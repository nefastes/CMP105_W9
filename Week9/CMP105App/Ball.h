#pragma once
#include "Framework/GameObject.h"
class Ball : public GameObject
{
private:


public:
	Ball();
	~Ball();

	void update(float dt) override;
};

