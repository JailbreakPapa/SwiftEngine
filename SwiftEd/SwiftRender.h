//DirectX Includes
#include <d3d11.h>
#include <D3Dcompiler.h>
//ImGUI Includes
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <vulkan/vulkan.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SwiftRender
{
	class SwiftDirectX11
	{
	
		
	};
	class SwiftVulkan
	{

	};
	class SwiftOGL
	{
	public:
	     GLint ShaderSuccess;
		 GLchar infoLog[512];
	private:
		 unsigned int VBO;
		 unsigned int VAO;
		 unsigned int vertexShader;
		 unsigned int fragmentShader;
		 unsigned int shaderProgram;
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

