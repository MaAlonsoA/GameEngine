#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Common/Scene.h"
#include "Player.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


enum class GameStatus : unsigned char {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
	GAME_LOSE
};

enum  Direction   {
	DIR_LEFT = -1,
	DIR_RIGTH = 1,
	DIR_UP =	1,
	DIR_DOWN = -1
};

class Game
{
private:
	GameStatus status;
	std::vector<std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Player> player;

public:
	void pushScene(std::shared_ptr<Scene> scene);
	std::vector<std::shared_ptr<Scene>> getScenes();
	Game();
	~Game();
	void update();
	void processImput(GLFWwindow* window);
	void setPlayer(std::shared_ptr<Player> p);
	std::shared_ptr<Player> getPlayer() const;
	void checkCollision();

};

