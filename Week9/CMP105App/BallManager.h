#pragma once
#include "Ball.h"
#include "Framework/Vector.h"
#include "math.h"

class BallManager
{
private:
	sf::Texture ballTex;
	sf::Vector2f spawnPoint;
	std::vector<Ball> balls;

public:
	BallManager();
	~BallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
};

