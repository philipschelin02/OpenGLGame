#pragma once

#include "Mesh.h"
#include "Material.h"
#include "Texture.h"
#include "../Maths/Matrix4x4.h"
#include <cmath>

class GameObject
{
	const Mesh* mesh;
	Material* material;
	Texture* texture;

public:
	float red; // add the colors as data members in the class
	float green; // why in the class, you ask?
	float blue; //
	Vector3 position = Vector3(0, 0, 0);
	Vector3 rotation = Vector3(0, 0, 0);
	GameObject(Material* _material, const Mesh* _mesh, Texture* _texture = nullptr) {
		mesh = _mesh;
		material = _material;
		texture = _texture;
	}
	void render() {
		material->use();

		// uniform
		int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColor");
		glUniform4f(tintLocation, red, green, blue, 1); //pass colors into uniform

		Matrix4x4 matTranslation = Matrix4x4::Translation(position);
		Matrix4x4 matRotation = Matrix4x4::Rotation(rotation);

		Matrix4x4 transform = matTranslation * matRotation;
		
		int transformLocation = glGetUniformLocation(material->shaderProgram, "transform");
		glUniformMatrix4fv(transformLocation, 1, GL_TRUE, &transform.m11);
		
		Matrix4x4 view = Matrix4x4::Translation(Vector3{ 0, 0,(sin(time) + 2) * -3 });
		unsigned int viewLoc = glGetUniformLocation(material->shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_TRUE, &view.m11);

		float fov = 45.0f / 360 * 2 * M_PI;
		float aspectRatio = 800.0f / 600;
		Matrix4x4 projection = Matrix4x4::Perspective(fov, aspectRatio, 0.1f, 100.0f);
		unsigned int projectionLoc = glGetUniformLocation(material->shaderProgram, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, &projection.m11);

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