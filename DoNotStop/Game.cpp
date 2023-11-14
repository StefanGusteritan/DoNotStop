#include "Game.h"


//Constructor
Game::Game
(
	//Window
	sf::VideoMode videoMode, std::string title, sf::Uint32 style,
	
	//Scene
	Scene activeScene, std::list<Scene> scenes
)
{
	this->windowInit(videoMode, title, style);
	this->scenes = scenes;
	this->activeScene = new Scene(activeScene);
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

void Game::setActiveScene(std::string name)
{
	for (auto scene : this->scenes)
	{
		if (scene.getName() == name)
		{
			this->activeScene = &scene;
		}
	}
}

void Game::updateSFMLEvents()
{
	while (this->window.pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{

			window.close();
		}

		for (auto updatable : this->activeScene->updatables)
		{
			if (updatable->isUpdateActive())
				updatable->updateSFMLEvents();
		}

	}


}

void Game::update()
{
	this->updateDeltaTile();
	this->updateSFMLEvents();

	for (auto updatable : this->activeScene->updatables)
	{
		if (updatable->isUpdateActive())
			updatable->update(this->dt);
	}
}

void Game::render()
{
	this->window.clear(sf::Color::Black);

	for (auto renderable : this->activeScene->renderables)
	{
		if (renderable->isRenderActive())
		{
			renderable->render(&this->window);
		}
	}


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
