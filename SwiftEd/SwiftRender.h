//DirectX Includes
#include <d3d11.h>
#include <D3Dcompiler.h>
//ImGUI Includes
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwiftRender
{
	class SwiftOGL
	{
	public:
	     GLint ShaderSuccess;
		 GLchar infoLog[512];
	public:
		// Create reference containers for the Vartex Array Object and the Vertex Buffer Object
		GLuint VAO, VBO;
		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;
		 enum SwiftShader
		 {
			 SWIFT_OGL_FRAG = 1,
			 SWIFT_OGL_VERT = 2,
		 };
	public:
		 void OpenGlRender();
		 void ShaderCompile(unsigned int Shader,const char* ShaderSource);
		void ShaderProgram(unsigned int fragShader, const char* fragShaderSource,unsigned int vertShader, const char* vertShaderSource);

	};
}

