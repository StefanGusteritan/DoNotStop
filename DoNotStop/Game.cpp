#include "Game.h"


//Constructor
Game::Game
(
	//Window
	sf::VideoMode videoMode,
	std::string title,
	sf::Uint32 style
)
{
	this->windowInit(videoMode, title, style);
}


//Initialization
void Game::windowInit(sf::VideoMode videoMode, std::string title, sf::Uint32 style)
{
	this->window.create(videoMode, title, style);
}


//Functions

void Game::updateDeltaTile()
{
	this->dt = this->dtClock.restart().asSeconds();
}

float Game::getDt()
{
	return this->dt;
}

void Game::updateSFMLEvents()
{
	while (this->window.pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{

			window.close();
		}

	}
}

void Game::update()
{
	this->updateDeltaTile();
	this->updateSFMLEvents();

}

void Game::render()
{
	this->window.clear(sf::Color::Black);



	this->window.display();
}


void Game::run()
{
	while (this->window.isOpen())
	{
		this->update();
		this->render();
	}
}
