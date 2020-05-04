#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Common/Scene.h"
#include "Common/GameObject.h"
#include "Common/Component.h"
#include "Common/Renderer.h"
#include "Game.h"




GLFWwindow* initWindow(unsigned SCR_WIDTH, unsigned SCR_HEIGHT);
void framebufferSizeCallback(GLFWwindow* window, int SCR_WIDTH, int SCR_HEIGHT);
void loadAssets();
void processImput(GLFWwindow* window);
void gameLoop(GLFWwindow* window);


int main() {
	const unsigned width{ 800 };
	const unsigned height{ 800 };

	GLFWwindow* window{ initWindow(width, height) };
	
	loadAssets();
	gameLoop(window);
	

};



GLFWwindow* initWindow(unsigned SCR_WIDTH, unsigned SCR_HEIGHT)
{
	GLFWwindow* window;
	void framebufferSizeCallback(GLFWwindow * window, int width, int height);


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false); // false to non sesiazable window

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
	return window;
}
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void loadAssets()
{

}

void processImput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void gameLoop(GLFWwindow* window)
{
	Game prueba;
	std::vector <float> positions{
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};
	std::vector <unsigned> indices{
		0, 1, 3,
		1, 2, 3
	};
	auto sandbox{ std::make_shared<Scene>() };
	auto prueba1{ std::make_shared<GameObject>() };
	auto render1{ std::make_shared<Renderer>(	"resources/shaders/shader2.vs", "resources/shaders/shader2.fs", positions, 5, indices,
												"resources/textures/charly.png", true
												) };
	prueba1->pushComponent(render1);
	sandbox->pushGameObject(prueba1);

	while (!glfwWindowShouldClose(window)) {

		processImput(window);
		
		//render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		
		sandbox->update();

		

		//glfw: swap buffer and poll IO event
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

}