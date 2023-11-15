#include "Game/Game.h"


void Renderable::render(sf::RenderWindow* window)
{
}

void Renderable::setRenderActiveState(bool active)
{
	//Sets the active state of the updatable

	this->renderActiveState = active;
}

bool Renderable::isRenderActive()
{
	// Returns the active state of the updatable

	return this->renderActiveState;
}

