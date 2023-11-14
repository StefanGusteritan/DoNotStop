#include "Game.h"


void Updatable::updateSFMLEvents()
{
}

void Updatable::update(float& dt)
{
}

void Updatable::setUpdateActiveState(bool active)
{
	//Sets the active state of the updatable
	
	this->updateActiveState = active;
}

bool Updatable::isUpdateActive()
{
	// Returns the active state of the updatable

	return this->updateActiveState;
}