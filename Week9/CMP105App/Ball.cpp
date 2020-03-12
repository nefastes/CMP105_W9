#include "Ball.h"
Ball::Ball()
{
	setOrigin(32, 32);
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	move(velocity * dt);
}