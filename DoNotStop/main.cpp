#include "Game.h"

int main()
{
	Game game
	(
		//Window
		sf::VideoMode(800, 600),
		"My Game",
		sf::Style::Default
	);

	game.run();
}