#include "Missile.h"
Missile::Missile()
{
	setOrigin(sf::Vector2f(8, 8));
}

Missile::~Missile()
{

}

void Missile::update(float dt)
{
	move(velocity * dt);
}