#include "Game/Game.h"

Scene::Scene(std::string name)
{
    this->name = name;
    updatables = {};
    renderables = {};
}

//Functions
std::string Scene::getName()
{
    return this->name;
}
