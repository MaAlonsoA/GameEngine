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



GLFWwindow* initWindow(unsigned SCR_WIDTH, unsigned SCR_HEIGHT);
void framebufferSizeCallback(GLFWwindow* window, int SCR_WIDTH, int SCR_HEIGHT);
void loadAssets();
void processImput(GLFWwindow* window);
void gameLoop(GLFWwindow* window);
const unsigned scr_width{ 1280 };
const unsigned scr_height{ 1024  };


int main() {
	
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

	GLFWwindow* window{ initWindow(scr_width, scr_height) };
	
	loadAssets();
	gameLoop(window);
	

};



GLFWwindow* initWindow(unsigned SCR_WIDTH, unsigned SCR_HEIGHT)
{
	GLFWwindow* window;
	void framebufferSizeCallback(GLFWwindow * window, int SCR_WIDTH, int SCR_HEIGHT);


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false); // false to non resiazable window

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
	
	auto level1{ std::make_shared<Level>("resources/levels/level1.txt") };

	prueba.pushScene(level1);
	



	/*auto sandbox{ std::make_shared<Scene>() };

	auto prueba1{ std::make_shared<GameObject>() };
	auto render1{ std::make_shared<Renderer>("resources/shaders/shader.vs", "resources/shaders/shader.fs", positions, 5, indices,
											"resources/textures/charly.png"
											) };

	auto transform1{ std::make_shared<Transform>() };
	prueba1->pushComponent(ComponentType::RENDERER, render1);
	prueba1->pushComponent(ComponentType::TRANSFORM, transform1);
	transform1->init();
	

	auto prueba2{ std::make_shared<GameObject>() };
 	auto render2{ std::make_shared<Renderer>(	"resources/shaders/shader2.vs", "resources/shaders/shader2.fs", positions, 5, indices,
												"resources/textures/pablo.png"
											) };

	auto transform2{ std::make_shared<Transform>() };
	prueba2->pushComponent(ComponentType::RENDERER, render2);
	prueba2->pushComponent(ComponentType::TRANSFORM, transform2);
	transform2->init();

	sandbox->pushGameObject(prueba1);
	sandbox->pushGameObject(prueba2);

	float f{ 0 };
	float increment{ 0.05 };
	float f2{ 0 };
	float increment2{ -0.05 };
	*/

	while (!glfwWindowShouldClose(window)) {

		processImput(window);
		
	/*	if (f > 15) increment = -0.5;
		else if (f < 0) increment = 0.5;
		f += increment;
		if (f2 < -15) increment2 = 0.5;
		else if (f2 > 0) increment2 = -0.5;
		f2 += increment2;*/

		//render

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		/*transform2->update(glm::vec2(-200.0f, 0.0f), glm::vec2(512.0f, 512.0f), f2);
		transform1->update(glm::vec2(300.0f, 0.0f), glm::vec2(512.0f, 512.0f), f);*/
		

		prueba.update();


		//glfw: swap buffer and poll IO event
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

}