#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Common/GameObject.h"
#include "Common/Component.h"
#include "Common/Renderer.h"
#include "Common//Transform.h"
#include "Game.h"
#include "Level.h"



GLFWwindow* initWindow(unsigned scrWidth, unsigned scrHeight);
void framebufferSizeCallback(GLFWwindow* window, int scrWidth, int scrHeight);
void loadAssets();
void gameLoop(GLFWwindow* window);
const unsigned scrWidth{ 800 };
const unsigned scrHeight{ 600  };


int main() {
	
	GLFWwindow* window{ initWindow(scrWidth, scrHeight) };
	
	loadAssets();
	gameLoop(window);

};



GLFWwindow* initWindow(unsigned scrWidth, unsigned scrHeight)
{
	GLFWwindow* window;
	void framebufferSizeCallback(GLFWwindow * window, int  scrWidth, int scrHeight);


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false); // false to non resiazable window

	window = glfwCreateWindow(scrWidth, scrHeight, "Mejor casi que hago el Sudoku", NULL, NULL);
	
	if (!window) {
		throw std::string{ "Failed to create GLFW window" };
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw std::string{ "Failed initialize GLAD" };
	}
	return window;
}
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void loadAssets()
{
	//to do
}



void gameLoop(GLFWwindow* window)
{
	Game prueba;
	
	auto level1{ std::make_shared<Level>("resources/levels/level1.txt") };
	prueba.pushScene(level1);
	prueba.setPlayer(std::static_pointer_cast<Player>(prueba.getScenes().front()->getEntities().at(1)));
	
	while (!glfwWindowShouldClose(window)) {

		while (prueba.getPlayer()->getLives() >= 0) {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			prueba.update();
			prueba.processImput(window);

			glfwSwapBuffers(window);
			glfwPollEvents();

		}
	}

}