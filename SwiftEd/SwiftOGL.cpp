#include "SwiftRender.h"
#include <iostream>
using namespace SwiftRender;
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};
int w = 2;
//our vertex Shader source. we will create a file type and read it there later...
const char* vertexShaderSource = "#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
void SwiftRender::SwiftOGL::OpenGlRender()
{
    SwiftOGL SGL;
    glGenBuffers(1, &SGL.VBO); //we need to store the vertex data, so we need to create a vertex buffer objec(VBO) to store the vertices.
    glBindBuffer(GL_ARRAY_BUFFER, SGL.VBO); //binds the buffer to opengl, so we can use it.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //gives Opengl data about the buffer.
    
    SGL.vertexShader = glCreateShader(GL_VERTEX_SHADER); //cretaes a vertex shader.
    SGL.ShaderCompile(vertexShader, vertexShaderSource);
    SGL.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    SGL.ShaderCompile(fragmentShader,fragmentShaderSource);
    SGL.ShaderProgram(fragmentShader, fragmentShaderSource, vertexShader, vertexShaderSource);
    glUseProgram(shaderProgram);
}

void SwiftRender::SwiftOGL::ShaderCompile(unsigned int Shader,const char* ShaderSource){
    glShaderSource(Shader, 1, &ShaderSource, NULL);
    glCompileShader(Shader);
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &ShaderSuccess);
    if (!ShaderSuccess) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "SwiftError: Shaders Failed To Compile. OPENGL, Shader Name: " << Shader << std::endl;
    }
    
}

void SwiftRender::SwiftOGL::ShaderProgram(unsigned int fragShader, const char* fragShaderSource, unsigned int vertShader, const char* vertShaderSource)
{
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &ShaderSuccess);
    if (!ShaderSuccess) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        
    }
  
}

