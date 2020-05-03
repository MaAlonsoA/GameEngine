#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Common/Game.h"
#include "Common/Scene.h"
#include "Common/GameObject.h"
#include "Common/Component.h"
#include "Common/Renderer.h"




GLFWwindow* initWindow(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT);
void framebufferSizeCallback(GLFWwindow* window, int SCR_WIDTH, int SCR_HEIGHT);
void loadAssets();
void processImput(GLFWwindow* window);
void gameLoop(GLFWwindow* window);


int main() {
	const unsigned int width{ 800 };
	const unsigned int height{ 600 };

	GLFWwindow* window{ initWindow(width, height) };
	loadAssets();
	gameLoop(window);
	

};



GLFWwindow* initWindow(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT)
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
	std::vector<float>vertices{ 
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f };
	Game breakOut;
	auto sandBox{ std::make_shared<Scene>() };
	auto triangulo1{ std::make_shared<GameObject>() };
	auto trianguloRender{ std::make_shared<Renderer>(	"resources/shaders/shader.vs", "resources/shaders/shader.fs", vertices, 3,
														"resources/textures/charly.png", true) };
	trianguloRender->initRenderer();
	triangulo1->pushComponent(trianguloRender);

	sandBox->pushGameObject(triangulo1);

	
	while (!glfwWindowShouldClose(window)) {

		processImput(window);

		//render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sandBox->update();

		//glfw: swap buffer and poll IO event
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

}