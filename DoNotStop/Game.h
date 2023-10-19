#pragma once
#include <iostream>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Updatable
{
	// Has update and updateSFMLEvents functions that are called each frame
private:
	// The active state if (false) update is not called
	bool activeState;

public:

	//Functions
	virtual void updateSFMLEvents();
	virtual void update();
	void setActiveState(bool active);
	bool isActive();
};


class Renderable
{
	// Has render function that is called each frame
private:
	// The active state if (false) render is not called
	bool activeState;

public:

	//Functions
	virtual void render(sf::RenderWindow* window);
	void setActiveState(bool active);
	bool isActive();
};



class Scene
{
private:
	std::string name;

public:
	//Constructor
	Scene(std::string name);

	//All Updatable objects in the scene
	std::list<Updatable*> updatables;

	//All renderalbe objects in the scene
	std::list<Renderable*> renderables;

	//Functions
	std::string getName();
};



class Game
{
private:

	//Variables
	sf::RenderWindow window;
	sf::Event sfEvent;
	
	sf::Clock dtClock;
	float dt;

	std::list<Scene> scenes;
	Scene *activeScene;

	//Initialization Functions
	void windowInit(sf::VideoMode videoMode, std::string tilte, sf::Uint32 style);
	void pixelsPerUnitInit(float pxPerUnit);

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
			sf::Uint32 style,

			// Pixels Per Unit
			float pxPerUnit,

			//Scene
			Scene activeScene,
			std::list <Scene> scenes
		);


	//Variables
	 
		// Pixel per Unit
		float u;


	//Functions
		void run();
		float getDt();
		void setActiveScene(std::string name);
};



