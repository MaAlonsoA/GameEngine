#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Common/Scene.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


enum class GameState : unsigned char {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
	GAME_LOSE
};

class Game
{
private:
	GameState state;
	std::vector<std::shared_ptr<Scene>> scenes;
	
public:
	void pushScene(std::shared_ptr<Scene> scene);
	Game();
	~Game();
	void update();

};

