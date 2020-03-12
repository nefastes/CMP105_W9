#include "MushManager.h"
MushManager::MushManager()
{
	mushTex.loadFromFile("gfx/MushroomTrans.png");
	aliveSprites = 0;

	for (unsigned i = 0; i < 40; ++i)
	{
		mushrooms.push_back(Mushroom());
		mushrooms[i].setAlive(false);
		mushrooms[i].setTexture(&mushTex);
		mushrooms[i].setSize(sf::Vector2f(64, 64));
	}
}

MushManager::~MushManager()
{

}

void MushManager::spawn()
{
	for (unsigned i = 0; i < mushrooms.size(); ++i)
	{
		if (!mushrooms[i].isAlive())
		{
			mushrooms[i].setVelocity(0, rand() % 400 + 200);
			mushrooms[i].setPosition(rand() % 1168 + 32, -32);
			mushrooms[i].setAlive(true);
			aliveSprites += 1;
			return;
		}
	}
}

void MushManager::update(float dt)
{
	for (unsigned i = 0; i < mushrooms.size(); ++i)				if (mushrooms[i].isAlive())				mushrooms[i].update(dt);
	deathCheck();
}

void MushManager::deathCheck()
{
	for (unsigned i = 0; i < mushrooms.size(); ++i)
		if(mushrooms[i].isAlive())
			if (mushrooms[i].getPosition().y > 675 - mushrooms[i].getSize().y / 2)
			{
				mushrooms[i].setAlive(false);
				aliveSprites -= 1;
			}
}

void MushManager::render(sf::RenderWindow* window)
{
	for (unsigned i = 0; i < mushrooms.size(); ++i)
		if (mushrooms[i].isAlive())
			window->draw(mushrooms[i]);

}

int MushManager::getAliveSprites()
{
	return aliveSprites;
}