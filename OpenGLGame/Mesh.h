#pragma once
#include <glad/glad.h>
class Mesh
{
    unsigned int VAO;
    size_t vertexCount;
public:

    void render() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }

	Mesh(float* vertices, size_t count) {
        vertexCount = count / 3;
        //Create vertex array object
       
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        //creates array buffer on gpu

        unsigned int VBO;
        glGenBuffers(1, &VBO); // ask open gl to create bufferie!!!!
        glBindBuffer(GL_ARRAY_BUFFER, VBO); //tell gl to use this buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, vertices, GL_STATIC_DRAW); //copy vertices to buffer


        //configure vertex attributes currently theres just one, namely the positions
        //so vertex understands where to find the input attributes, posotion in this case
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
	}
};