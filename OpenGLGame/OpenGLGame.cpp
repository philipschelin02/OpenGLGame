#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "GameObject.h"
#include "stb_image.h"
#include "Texture.h"
#include <vector>
using namespace std;
void processInput(GLFWwindow*);

int main() {

    Window window{ 800,600 };

    Texture container{ "container.jpg", GL_TEXTURE0 };

    Texture wall{ "wall.jpg", GL_TEXTURE1 };

    Vertex vertices[]{
           Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
           Vertex{Vector3{ 0.0f, -0.5f, 0.0f}},
           Vertex{Vector3{-0.5f,  0.5f, 0.0f}},
           Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
           Vertex{Vector3{-0.5f,  0.5f, 0.0f}},
           Vertex{Vector3{-1.0f, 0.5f, 0.0f}}
    };
    // Variable to store buffer id
    Mesh mesh1{ vertices, size(vertices) };

    Vertex vertices2[]{
        //triangle tv�
         Vertex{Vector3{0.0f, -0.5f, 0.0f},Color::red}, // A
         Vertex{Vector3{1.0f,  -0.5f, 0.0f},Color::green}, // B
         Vertex{Vector3{0.5f,  0.5f, 0.0f},Color::blue}
    };
    
    Mesh mesh2{ vertices2, size(vertices2) };

    

    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};

    Shader orangeShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader yellowShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader textureShader{ "blendTexturesFragmentShader.glsl", GL_FRAGMENT_SHADER };

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material yellow{ vertexShader, yellowShader };
    Material texture{ vertexShader, textureShader };


    GameObject a{ &orange, &mesh1 };
    a.red = 1;
    GameObject b{ &yellow, &mesh2 };
    b.blue = 1;
    GameObject c{ &texture, Mesh::createQuad(), &wall};
    c.position = Vector3(-0.75f, 0, 0);
    GameObject d{ &texture, Mesh::createQuad(), &container};
    d.position = Vector3(0.75f, 0, 0);

    // while the user does not want to quit, (x button, alt f4)
    while (!window.shouldClose())
    {
        //process input (eg close window on esc)
         //uhmmmm???
        window.processInput();

        //render (paint current frame of game)
        window.clear();

        //dry principle
        //dont repeat urself
        c.rotation.y = glfwGetTime();
        d.rotation.z = glfwGetTime();
        
        a.render();
        b.render();
        //c.horizontalOffset = cos(glfwGetTime());
        c.render();
        d.render();
        window.present();
    }
    //cleans upp all the glfw stuffies
    glfwTerminate();
    return 0;
}