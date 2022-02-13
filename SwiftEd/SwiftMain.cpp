#include "SwiftRender.h"
#include <iostream>
void FBWindowDraw(GLFWwindow* window, int width, int height);

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
	while (!glfwWindowShouldClose(SwiftOGLWindow)) {
		glfwSwapBuffers(SwiftOGLWindow);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void FBWindowDraw(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
