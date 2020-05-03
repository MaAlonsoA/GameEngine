#include "Game.h"

void Game::update()
{
	for (auto& elem : scenes)
		elem->update();
}


void Game::pushScene(std::shared_ptr<Scene> scene)
{
	scenes.push_back(scene);
}

//**************************** PUBLIC *********************************************//
Game::Game() {}

Game::~Game()
{

}


