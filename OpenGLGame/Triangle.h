#pragma once

#include "Mesh.h"
#include "Material.h"

class Triangle
{
	Mesh* mesh;
	Material* material;

public:
	float red; // add the colors as data members in the class
	float green; // why in the class, you ask?
	float blue; //
	Triangle(Material* _material, Mesh* _mesh) {
		mesh = _mesh;
		material = _material;
	}
	void render() {
		material->use();

		int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");

		glUniform4f(tintLocation, red, green, blue, 1); //pass colors into uniform

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