#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include <math.h>

#include "Helper.h"
#include "Enviroment.h"
#include "Enemy.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define LOG(x) std::cout << x << std::endl

// void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void)
{
	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGLSniper", NULL, NULL);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);
	// glfwSetKeyCallback(window, keyCallback);
	// glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	Helper helper = Helper();
	Enviroment enviroment = Enviroment();
	Enemy enemy = Enemy();

	helper.setup(window, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// Render OpenGL here
		enviroment.init();
		enemy.render();
		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

/*
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	LOG(key);

	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
	if (key == GLFW_KEY_SPACE && action == GLFW_REPEAT)
	{
		LOG("Space Key Pressed");
	}
	if (key == GLFW_KEY_RIGHT)
	{
		Helper().moveQuadToRight(quadVertices);
		LOG("Move to right");
	}
	if (key == GLFW_KEY_LEFT)
	{
		Helper().moveQuadToLeft(quadVertices);
		LOG("Move to left");
	}
	if (key == GLFW_KEY_UP)
	{
		Helper().scaleQuadUpper(quadVertices);
		LOG("Scale Upper");
	}
	if (key == GLFW_KEY_DOWN)
	{
		Helper().scaleQuadDown(quadVertices);
		LOG("Scale Down");
	}
}
*/