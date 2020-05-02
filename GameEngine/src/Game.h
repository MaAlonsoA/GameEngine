#pragma once

#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


enum GameState : unsigned char {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN,
	GAME_LOSE
};

class Game
{
private:
	unsigned int SCR_WIDTH{1920};
	unsigned int SCR_HEIGHT{1080};
	GameState state;
	GLFWwindow* window;
	void initWindow();
	void gameLoop();
	void loadAssets();
	void processImput(GLFWwindow*);
	void update();
public:
	Game();
	~Game();
	void run();

};

