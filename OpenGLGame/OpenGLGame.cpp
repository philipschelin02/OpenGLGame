#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"
#include "stb_image.h"
using namespace std;
void processInput(GLFWwindow*);

int main() {

    Window window{ 800,600 };

    int width, height, nrChannels;
    unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    unsigned int textureId;
    glGenTextures(1, &textureId);
    glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    //real program starts here!!!!!!

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
        //triangle två
         Vertex{Vector3{0.0f, -0.5f, 0.0f},Color::red}, // A
         Vertex{Vector3{1.0f,  -0.5f, 0.0f},Color::green}, // B
         Vertex{Vector3{0.5f,  0.5f, 0.0f},Color::blue}
    };
    
    Mesh mesh2{ vertices2, size(vertices2) };

    Vertex vertices3[]{
            // positions                // colors           // texture coords
    Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Color::red,    Vector2{0.5f, 0.5f}},   // top right
    Vertex{Vector3{ 0.5f, -0.5f, 0.0f},   Color::green,  Vector2{0.5f, -0.5f}},   // bottom right
    Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Color::blue,   Vector2{-0.5f, -0.5f}},   // bottom left
    
    Vertex{Vector3{-0.5f,  0.5f, 0.0f},   Color::yellow, Vector2{-0.5f, 0.5f}},    // top left
    Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Color::red,    Vector2{0.5f, 0.5f}}, 
    Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Color::blue,   Vector2{-0.5f, -0.5f}} 
    };

    Mesh mesh3{ vertices3, size(vertices3) };

    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};

    Shader orangeShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader yellowShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader textureShader{ "textureFragmentShader.glsl", GL_FRAGMENT_SHADER };

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material yellow{ vertexShader, yellowShader };
    Material texture{ vertexShader, textureShader };


    Triangle a{ &orange, &mesh1 };
    a.red = 1;
    Triangle b{ &yellow, &mesh2 };
    b.blue = 1;
    Triangle c{ &texture, &mesh3 };

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
        c.render();
        
        window.present();
    }
    //cleans upp all the glfw stuffies
    glfwTerminate();
    return 0;
}