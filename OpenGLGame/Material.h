#pragma once
#include "glad/glad.h"
#include "Shader.h"
class Material
{
public:
	Material(Shader vertexShader, Shader& fragmentShader) 
	{
		unsigned int shaderProgram;
		shaderProgram { glCreateProgram() };
		glAttachShader(orangeShaderProgram, vertexShader.shaderId);
		glAttachShader(orangeShaderProgram, orangeFragmentShader);
		glLinkProgram(orangeShaderProgram);
	}
};

