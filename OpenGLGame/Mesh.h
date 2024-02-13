#pragma once
#include <glad/glad.h>
#include <cstddef>
#include "../Maths/Vector3.h"
#include <algorithm>

struct Vector2 {
    float u, v;
};

struct Color {
    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color yellow;
    float r, g, b, a;
};


struct Vertex {
    Vector3 pos;
    Color col{ 1,1,1,1 };
    Vector2 uv; // texture coords
};

class Mesh
{
    unsigned int VAO;
    size_t vertexCount;

    const static Vertex quadVertices[6]; // here we declare vertices
    static Mesh* quadMesh;

    const static Vertex triangleVertices[3];
    static Mesh* triangleMesh;
    //do same for trinagle
    // keep as is
    // rotate around itself
    // literally how aaaaaa
    //bonus: calculate the right coords
    //do same for box
    //6 sides, -0.5 -> 0.5 on all axes (x,y,z)
    const static Vertex cubeVertices[36];
    static Mesh* cubeMesh;

public:

    //publc static methord to create quad mesh

    static const Mesh* createQuad() {
        if (quadMesh == nullptr) {
            quadMesh = new Mesh{ Mesh::quadVertices, std::size(Mesh::quadVertices) };
        }
        return quadMesh;
    }

    static const Mesh* createTriangle() {
        if (triangleMesh == nullptr) {
            triangleMesh = new Mesh{ Mesh::triangleVertices, std::size(Mesh::triangleVertices) };
        }
        return triangleMesh;
    }

    static const Mesh* createCube() { // NEW: function to create (or get) a quad mesh
        if (!cubeMesh) { // NEW: initialize, if not happened, yet
            cubeMesh = new Mesh{ Mesh::cubeVertices, std::size(Mesh::cubeVertices) };
        }
        return cubeMesh; // NEW: return quad mesh
    }

    void render() const {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }

	Mesh(const Vertex* vertices, size_t count) {
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

        //what to change for new uv attribute?
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
        glEnableVertexAttribArray(2);
	}
};

//define vertices omg

