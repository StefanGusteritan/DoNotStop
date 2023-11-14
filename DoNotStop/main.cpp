#include "Game.h"

class Test : public Renderable, public Updatable
{
private:
	sf::CircleShape circle;
	float speed = 50;

public:
	Test()
	{
		this->setRenderActiveState(true);
		this->setUpdateActiveState(true);
		circle.setRadius(20);
		circle.setFillColor(sf::Color::Blue);
		circle.setPosition(0, 0);
	}

	void render(sf::RenderWindow* window) override
	{
		window->draw(circle);
		
	}

	void update(float& dt) override
	{
		if (this->circle.getPosition().x < 200)
			this->circle.move(speed * dt, 0);
	}

};


int main()
{
	std::list<Scene> scenes = {};
	Scene scene("main");

	Test a;
	scene.renderables.push_back(&a);
	scene.updatables.push_back(&a);

	scenes.push_back(scene);

	Game game
	(
		//Window
		sf::VideoMode(800, 600),
		"My Game",
		sf::Style::Default,


		//Scene
		scene,
		scenes
	);

	game.run();
}


