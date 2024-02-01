#pragma once

#include "Mesh.h"
#include "Material.h"
#include "Texture.h"

class Triangle
{
	Mesh* mesh;
	Material* material;
	Texture* texture;

public:
	float red; // add the colors as data members in the class
	float green; // why in the class, you ask?
	float blue; //
	float horizontalOffset;
	Triangle(Material* _material, Mesh* _mesh, Texture* _texture = nullptr) {
		mesh = _mesh;
		material = _material;
		texture = _texture;
	}
	void render() {
		material->use();

		// uniform
		int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");
		glUniform4f(tintLocation, red, green, blue, 1); //pass colors into uniform
		
		int offSetLocation = glGetUniformLocation(material->shaderProgram, "horizontalOffset");
		glUniform1f(offSetLocation, horizontalOffset); //pass colors into uniform
		
		int diffuseLocation = glGetUniformLocation(material->shaderProgram, "diffuseLocation");
		glUniform1i(diffuseLocation, 0); //pass colors into uniform
		
		glActiveTexture(GL_TEXTURE0);
		
		if (texture != nullptr)
			glBindTexture(GL_TEXTURE_2D, texture->textureId);
		else
			glBindTexture(GL_TEXTURE_2D, 0);

		int blendLocation = glGetUniformLocation(material->shaderProgram, "blendTexture");
		glUniform1i(blendLocation, 1); //pass colors into uniform



		mesh->render();
	}
};


// extend the triangle to have data members
// red green and blue
// pass those data members to the uniform
// in the main function, pass in red color (1,0,0) for the first triangle
// and green color (0,1,0) for the second triangle

// result is one red, one green triangle
// both using the same shader