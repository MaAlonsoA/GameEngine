#include "Game.h"

void Game::initWindow()
{
	void framebufferSizeCallback(GLFWwindow * window, int width, int height);


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Mejor casi que hago el Sudoku", NULL, NULL);
	if (!window) {
		throw std::string{ "Failed to create GLFW window" };
		glfwTerminate();
	} 
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::string{ "Failed initialize GLAD" };
	}
}
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Game::gameLoop()
{

	while (!glfwWindowShouldClose(window)) {
		
		processImput(window);

		//render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//glfw: swap buffer and poll IO event
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	
}

void Game::loadAssets()
{

}

void Game::processImput(GLFWwindow*)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Game::update()
{

}

//**************************** PUBLIC *********************************************//
Game::Game() {}

Game::~Game()
{

}

void Game::run()
{
	initWindow();
	gameLoop();
}

