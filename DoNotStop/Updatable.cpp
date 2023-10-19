#include "Game.h"


void Updatable::updateSFMLEvents()
{
}

void Updatable::update()
{
}

void Updatable::setActiveState(bool active)
{
	//Sets the active state of the updatable
	
	this->activeState = active;
}

bool Updatable::isActive()
{
	// Returns the active state of the updatable

	return this->activeState;
}