#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
private:

	//Variables
	sf::RenderWindow window;
	sf::Event sfEvent;
	
	sf::Clock dtClock;
	float dt;

	//Initialization Functions
	void windowInit(sf::VideoMode videoMode, std::string tilte, sf::Uint32 style);

	//Functons
	void updateDeltaTile();
	void updateSFMLEvents();
	void update();
	void render();

public:

	//Constructor
	Game
	(
		//Window
		sf::VideoMode videoMode,
		std::string title,
		sf::Uint32 style
	);

	//Functions
	void run();
	float getDt();
};

