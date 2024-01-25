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

    Mesh mesh1{vertices, size(vertices)};
    
    float vertices2[]{
        //triangle två
         0.0f, -0.0f, 0.0f,
         0.45f, 0.5f, 0.0f,
         0.9f,  0.0f, 0.0f
    };

    Mesh mesh2{ vertices2, size(vertices2) };

    unsigned int VAO2;
    glGenVertexArrays(1, &VAO2);
    glBindVertexArray(VAO2);

    unsigned int VBO2;
    glGenBuffers(1, &VBO2); // ask open gl to create bufferie!!!!
    glBindBuffer(GL_ARRAY_BUFFER, VBO2); //tell gl to use this buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW); //copy vertices to buffer


    //configure vertex attributes currently theres just one, namely the positions
    //so vertex understands where to find the input attributes, posotion in this case
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Compile vertex shaderie on gpuie
    
    Shader vertexShader{};

    // ------ Compile the Orange Fragment Shader on the GPU --------
    const char* orangeFragmentShaderSource{ "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0" };
    unsigned int orangeFragmentShader;
    orangeFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(orangeFragmentShader, 1, &orangeFragmentShaderSource, NULL);
    glCompileShader(orangeFragmentShader);

    // ------ Compile the Yellow Fragment Shader on the GPU --------
    const char* yellowFragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "} \0";
    unsigned int yellowFragmentShader{ glCreateShader(GL_FRAGMENT_SHADER) };
    glShaderSource(yellowFragmentShader, 1, &yellowFragmentShaderSource, NULL);
    glCompileShader(yellowFragmentShader);

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{vertexShader, orangeShader};
    Material yellow{ vertexShader, yellowShader };

    Triangle a{ &orange, &mesh1 };
    Triangle b{ &yellow, &mesh1 };

    // -------- Create Yellow Shader Program (Render Pipeline) ---------
    unsigned int yellowShaderProgram{ glCreateProgram() };
    glAttachShader(yellowShaderProgram, vertexShader.shaderId);
    glAttachShader(yellowShaderProgram, yellowFragmentShader);
    glLinkProgram(yellowShaderProgram);

    //cleanie uppie shadies!!!!
    glDeleteShader(orangeFragmentShader);
    glDeleteShader(yellowFragmentShader);

    Triangle a{&orange}

    // while the user does not want to quit, (x button, alt f4)
    while (!window.shouldClose())
    {
        //process input (eg close window on esc)
        glfwPollEvents(); //uhmmmm???
        window.processInput();

        //render (paint current frame of game)
        glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //dry principle
        //dont repeat urself
        mesh1.render();
        orange.use;

        yellow.use;
        mesh2.render();
        window.present();
    }
    //cleans upp all the glfw stuffies
    glfwTerminate();
    return 0;
}