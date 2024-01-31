#pragma once
#include <glad/glad.h>
#include <cstddef>

struct Vector3 {
    float x, y, z;
};

struct Color {
    static const Color red;
    static const Color green;
    static const Color blue;
    float r, g, b, a;
};


struct Vertex {
    Vector3 pos;
    Color col{ 1,1,1,1 };
};

class Mesh
{
    unsigned int VAO;
    size_t vertexCount;
public:

    void render() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }

	Mesh(Vertex* vertices, size_t count) {
        vertexCount = count;
        //Create vertex array object
       
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        //creates array buffer on gpu

        unsigned int VBO;
        glGenBuffers(1, &VBO); // ask open gl to create bufferie!!!!
        glBindBuffer(GL_ARRAY_BUFFER, VBO); //tell gl to use this buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, vertices, GL_STATIC_DRAW); //copy vertices to buffer


        //configure vertex attributes currently theres just one, namely the positions
        //so vertex understands where to find the input attributes, posotion in this case
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, col));
        glEnableVertexAttribArray(1);
	}
};