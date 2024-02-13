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

    // Variable to store buffer id

    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER};

    Shader orangeShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader textureShader{ "blendTexturesFragmentShader.glsl", GL_FRAGMENT_SHADER };

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material texture{ vertexShader, textureShader };

    GameObject cube{ &texture, Mesh::createCube(), &wall };

    // while the user does not want to quit, (x button, alt f4)
    while (!window.shouldClose())
    {
        //process input (eg close window on esc)
         //uhmmmm???
        window.processInput();

        //render (paint current frame of game)
        window.clear();

        cube.rotation.x = glfwGetTime();
        cube.rotation.y = glfwGetTime() * 0.8f;
        cube.rotation.z = glfwGetTime() * 0.6f;
        cube.render();


        window.present();
    }
    //cleans upp all the glfw stuffies
    glfwTerminate();
    return 0;
}