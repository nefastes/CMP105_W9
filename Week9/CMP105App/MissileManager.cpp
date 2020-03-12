#include "MissileManager.h"
MissileManager::MissileManager()
{
	aliveSprites = 0;
	missileTex.loadFromFile("gfx/Missile.png");

	//Start with just one missile
	missiles.push_back(Missile());
	missiles[missiles.size() - 1].setAlive(false);
	missiles[missiles.size() - 1].setTexture(&missileTex);
	missiles[missiles.size() - 1].setSize(sf::Vector2f(64, 64));
}

MissileManager::~MissileManager()
{

}

void MissileManager::spawn(sf::Vector2f pPos, sf::Vector2f mPos)
{
	//Adjust position and vel
	spawnPoint = pPos;
	tempVel = mPos - pPos;
	
	for (unsigned i = 0; i < missiles.size(); ++i)
	{
		if (!missiles[i].isAlive())
		{
			missiles[i].setPosition(spawnPoint);
			missiles[i].setVelocity(tempVel);
			missiles[i].setAlive(true);
			aliveSprites += 1;
			return;
		}
	}
	missiles.push_back(Missile());
	missiles[missiles.size() - 1].setAlive(true);
	missiles[missiles.size() - 1].setTexture(&missileTex);
	missiles[missiles.size() - 1].setSize(sf::Vector2f(64, 64));
	missiles[missiles.size() - 1].setPosition(spawnPoint);
	missiles[missiles.size() - 1].setVelocity(tempVel);
	aliveSprites += 1;
}

void MissileManager::update(float dt)
{
	for (unsigned i = 0; i < missiles.size(); ++i)				if (missiles[i].isAlive())				missiles[i].update(dt);
	deathCheck();
}

void MissileManager::deathCheck()
{
	for (unsigned i = 0; i < missiles.size(); ++i)
	{
		if (missiles[i].isAlive())
		{
			if (missiles[i].getPosition().x < 0 + missiles[i].getSize().x / 2)
			{
				missiles[i].setAlive(false);
				aliveSprites -= 1;
			}
			if (missiles[i].getPosition().x > 1200 - missiles[i].getSize().x / 2)
			{
				missiles[i].setAlive(false);
				aliveSprites -= 1;
			}
			if (missiles[i].getPosition().y < 0 + missiles[i].getSize().y / 2)
			{
				missiles[i].setAlive(false);
				aliveSprites -= 1;
			}
			if (missiles[i].getPosition().y > 675 - missiles[i].getSize().y / 2)
			{
				missiles[i].setAlive(false);
				aliveSprites -= 1;
			}
		}
	}
}

void MissileManager::render(sf::RenderWindow* window)
{
	for (unsigned i = 0; i < missiles.size(); ++i)
		if (missiles[i].isAlive())
			window->draw(missiles[i]);
}

int MissileManager::getAliveSprites()
{
	return aliveSprites;
}