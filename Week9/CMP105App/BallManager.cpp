#include "BallManager.h"
#include <iostream>
BallManager::BallManager()
{
	ballTex.loadFromFile("gfx/Beach_Ball.png");
	spawnPoint = sf::Vector2f(400, 400);

	for (unsigned i = 0; i < 3; ++i)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&ballTex);
		balls[i].setSize(sf::Vector2f(64, 64));
	}
}

BallManager::~BallManager()
{

}

void BallManager::spawn()
{
	for (unsigned i = 0; i < balls.size(); ++i)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setPosition(spawnPoint);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setAlive(true);
			return;
		}
	}
	balls.push_back(Ball());
	balls[balls.size()-1].setAlive(true);
	balls[balls.size()-1].setTexture(&ballTex);
	balls[balls.size()-1].setSize(sf::Vector2f(64, 64));
	std::cout << balls.size() << std::endl;
}

void BallManager::update(float dt)
{
	for (unsigned i = 0; i < balls.size(); ++i)			if (balls[i].isAlive())					balls[i].update(dt);
	deathCheck();
}

void BallManager::deathCheck()
{
	for (unsigned i = 0; i < balls.size(); ++i)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < 0 + balls[i].getSize().x / 2)					balls[i].setAlive(false);
			if (balls[i].getPosition().x > 1200 - balls[i].getSize().x / 2)					balls[i].setAlive(false);
			if (balls[i].getPosition().y < 0 + balls[i].getSize().y / 2)					balls[i].setAlive(false);
			if (balls[i].getPosition().y > 675 - balls[i].getSize().y / 2)					balls[i].setAlive(false);
		}
	}
}

void BallManager::render(sf::RenderWindow* window)
{
	for (unsigned i = 0; i < balls.size(); ++i)			if (balls[i].isAlive())					window->draw(balls[i]);
}