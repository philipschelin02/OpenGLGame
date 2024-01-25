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
		glAttachShader(shaderProgram, vertexShader.shaderId);
		glAttachShader(shaderProgram, fragmentShader.shaderId);
		glLinkProgram(shaderProgram);
	}
	void use() {
		glUseProgram(shaderProgram);
	}
};

