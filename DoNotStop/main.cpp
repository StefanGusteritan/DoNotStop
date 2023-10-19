#include "Game.h"

class Test : public Renderable
{
private:
	sf::CircleShape circle;


public:
	Test()
	{
		this->setActiveState(true);
		circle.setRadius(2);
		circle.setFillColor(sf::Color::Blue);
		circle.setPosition(0, 0);
	}

	void render(sf::RenderWindow* window) override
	{
		window->draw(circle);
		
	}
};


int main()
{
	std::list<Scene> scenes = {};
	Scene scene("main");

	Test a;
	scene.renderables.push_back(&a);

	scenes.push_back(scene);

	Game game
	(
		//Window
		sf::VideoMode(800, 600),
		"My Game",
		sf::Style::Default,

		//Pixels Per Unit
		100,

		//Scene
		scene,
		scenes
	);

	game.run();
}


