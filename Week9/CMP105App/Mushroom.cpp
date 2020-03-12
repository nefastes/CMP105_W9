#include "Mushroom.h"
Mushroom::Mushroom()
{
	setOrigin(sf::Vector2f(32, 32));
}

Mushroom::~Mushroom()
{

}

void Mushroom::update(float dt)
{
	move(velocity * dt);
}