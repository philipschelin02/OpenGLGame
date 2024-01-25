#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

class Window {

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    static void error_callback(int error, const char* msg) {
        cerr << " [" << error << "] " << msg << endl;
    }
    GLFWwindow* window;
    
public:
    
    bool success{};

	Window(int width, int height) {
        glfwSetErrorCallback(error_callback);

        // Initialie GLFW
        if (!glfwInit()) { // Exit if failed
            cout << "Failed to init GLFW" << endl;
            success = false;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        //Create Window/Request it from OS
        window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        
        if (window == nullptr)
        {
            cout << "Failed to create GLFW window" << endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);

        //initialisera glad (ja e glad för jag vann på lotto!!!!) (connects opengl functiosn)
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            cout << "Failed to initialize GLAD" << endl;
            return;
        }

        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        //init ends here
        success = true; //we set success to be truesies
	}

    void processInput()
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(this->window, true);
    }

    void present() {
        glfwSwapBuffers(window);
    }

    bool shouldClose() {
        return glfwWindowShouldClose(this->window);
    }
};