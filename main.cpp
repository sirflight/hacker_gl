#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <sstream>

int windowWidth = 800;
int windowHeight = 600;

GLFWwindow* gameWindow;

void windowResizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void initializeGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	
}

void initializeWindow()
{
	gameWindow = glfwCreateWindow(windowWidth, windowHeight, "Game", NULL, NULL);
	if(gameWindow == NULL)
	{
		std::cout << "Failed to create window!!" << std::endl;
		glfwTerminate();
		exit(0);
	}	
	glfwMakeContextCurrent(gameWindow);
}

void initializeGlad()
{
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD!!" << std::endl;
		glfwTerminate();
		exit(0);
	}
}

void updateInput(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void render()
{
	glClearColor(0.25f, 0.35f, 0.35f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);	
}

int main()
{
	initializeGLFW();
	initializeWindow();
	initializeGlad();

	glViewport(0, 0, windowWidth, windowHeight);
	glfwSetFramebufferSizeCallback(gameWindow, windowResizeCallback);

	while(!glfwWindowShouldClose(gameWindow))
	{
		updateInput(gameWindow);
		
		render();

		glfwSwapBuffers(gameWindow);
		glfwPollEvents();
	}
	
	return 0;
}
