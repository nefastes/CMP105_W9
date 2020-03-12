#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	prevSpawn = 0;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf")) std::cout << "Could not load font.\n";
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(0, 0);

	playerTex.loadFromFile("gfx/Player.png");
	player.setInput(input);
	player.setWindow(window);
	player.setTexture(&playerTex);
	player.setSize(sf::Vector2f(128, 128));
	player.setOrigin(sf::Vector2f(player.getSize().x / 2, player.getSize().y / 2));
	player.setPosition(444, 0 + player.getSize().y);
	player.setVelocity(sf::Vector2f(200.f, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);

	prevSpawn += dt;
	if (input->isKeyDown(sf::Keyboard::F) && prevSpawn > .1f)
	{
		ballManager.spawn();
		prevSpawn = 0;
	}
	if (input->isKeyDown(sf::Keyboard::G) && prevSpawn > .1f)
	{
		mushManager.spawn();
		prevSpawn = 0;
	}
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	ballManager.update(dt);
	mushManager.update(dt);
	text.setString("Balls: " + std::to_string(ballManager.getAliveSprites()) + "\nMushrooms: " + std::to_string(mushManager.getAliveSprites()));
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager.render(window);
	mushManager.render(window);
	window->draw(player);
	window->draw(text);
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