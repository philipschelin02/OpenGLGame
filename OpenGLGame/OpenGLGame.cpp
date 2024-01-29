#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"
using namespace std;
void processInput(GLFWwindow*);

int main() {

    Window window{ 800 ,600 };

    //real program starts here!!!!!!

    float vertices[]{
           -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, 0.5f, 0.0f
    };
    // Variable to store buffer id

    Mesh mesh1{ vertices, size(vertices) };

    float vertices2[]{
        //triangle två
         0.0f, -0.0f, 0.0f,
         0.45f, 0.5f, 0.0f,
         0.9f,  0.0f, 0.0f
    };
    
    Mesh mesh2{ vertices2, size(vertices2) };

    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};

    Shader orangeShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader yellowShader{ "yellowFragmentShader.glsl", GL_FRAGMENT_SHADER};

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material yellow{ vertexShader, yellowShader };

    Triangle a{ &orange, &mesh1 };
    Triangle b{ &yellow, &mesh2 };

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
        
        a.render();
        b.render();
        
        window.present();
    }
    //cleans upp all the glfw stuffies
    glfwTerminate();
    return 0;
}