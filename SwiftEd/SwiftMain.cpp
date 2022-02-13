#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "SwiftRender.h"
// Vertex Shader source code
using namespace SwiftRender;
SwiftRender::SwiftOGL SGL;

void DynamicViewPort(GLFWwindow* Window,int width,int height);

int main(int argc,char** argv[])
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "SwiftEngine - OpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glfwSetFramebufferSizeCallback(window, DynamicViewPort);
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		SGL.OpenGlRender();
		// Tell OpenGL which Shader Program we want to use
		glUseProgram(SGL.shaderProgram);
		// Bind the VAO so OpenGL knows to use it
		glBindVertexArray(SGL.VAO);
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	glDeleteVertexArrays(1, &SGL.VAO);
	glDeleteBuffers(1, &SGL.VBO);
	glDeleteProgram(SGL.shaderProgram);
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	delete(&SGL);
	
	glfwTerminate();
	return 0;
}

void DynamicViewPort(GLFWwindow* Window,int width,int height)
{
	glViewport(0, 0, width, height);
}
