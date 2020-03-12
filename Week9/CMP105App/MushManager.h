#pragma once
#include "Mushroom.h"
class MushManager
{
private:
	sf::Texture mushTex;
	sf::Vector2f spawnPoint;
	std::vector<Mushroom> mushrooms;

	int aliveSprites;

public:
	MushManager();
	~MushManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

	int getAliveSprites();
};

