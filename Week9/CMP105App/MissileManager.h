#pragma once
#include "Missile.h"
class MissileManager
{
private:
	sf::Texture missileTex;
	sf::Vector2f spawnPoint;
	sf::Vector2f tempVel;
	std::vector<Missile> missiles;

	int aliveSprites;

public:
	MissileManager();
	~MissileManager();

	void spawn(sf::Vector2f pPos, sf::Vector2f mPos);
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

	int getAliveSprites();
};

