#include "SwiftRender.h"
#include <iostream>
#include <io.h>
using namespace SwiftRender;
SwiftOGL SGL;
void FBWindowDraw(GLFWwindow* window, int width, int height);
void SwiftProssessInput(GLFWwindow* window);
int main(int argv, char** argc)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); /* States to glfw our GLFW Version. This is the version that all MODERN GPUS should support.*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Start of Window Creation.
	GLFWwindow* SwiftOGLWindow = glfwCreateWindow(1078, 600, "SwiftEngine - OpenGL", NULL, NULL);
	if (SwiftOGLWindow == NULL){
		std::cout << "SwiftError: Failed To Create OGL Window." << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(SwiftOGLWindow); //makes OGL Focus on this main Window.
	//Since we will need glad, we will init it, then check if it failed.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "SwiftError: Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//function, that dynamicly resizes the OGL Viewport,and tells glad to call the function by tick, and resize the viewport.
	glfwSetFramebufferSizeCallback(SwiftOGLWindow, FBWindowDraw);
	//Start of imgui
	
	//======imgui
	while (!glfwWindowShouldClose(SwiftOGLWindow)) {
		SwiftProssessInput(SwiftOGLWindow);
		//rendering code goes here.

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		SGL.OpenGlRender();

		//end of rendering code.
		glfwSwapBuffers(SwiftOGLWindow);
		glfwPollEvents();
	}
	glDeleteShader(SGL.fragmentShader);
	glDeleteShader(SGL.vertexShader);
	glDeleteVertexArrays(1, &SGL.VAO);
	glDeleteBuffers(1, &SGL.VBO);
	glDeleteBuffers(1, &SGL.EBO);
	glfwTerminate();
	return 0;
}

void FBWindowDraw(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void SwiftProssessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_F12) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
