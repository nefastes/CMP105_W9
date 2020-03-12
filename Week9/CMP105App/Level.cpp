#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	prevSpawn = 0;

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	prevSpawn += dt;
	if (input->isKeyDown(sf::Keyboard::F) && prevSpawn > .1f)
	{
		ballManager.spawn();
		prevSpawn = 0;
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}