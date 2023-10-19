#include "Game.h"


void Renderable::render(sf::RenderWindow* window)
{
}

void Renderable::setActiveState(bool active)
{
	//Sets the active state of the updatable

	this->activeState = active;
}

bool Renderable::isActive()
{
	// Returns the active state of the updatable

	return this->activeState;
}

