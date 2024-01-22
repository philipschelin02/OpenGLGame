#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

using namespace std;

void error_callback(int error, const char* msg) {
    string s;
    s = " [" + to_string(error) + "] " + msg + '\n';
    cerr << s << endl;
}

int main() {
    
    glfwSetErrorCallback(error_callback);
    
    // Initialie GLFW
    if (!glfwInit()) { // Exit if failed
        cout << "Failed to init GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Create Window/Request it from OS
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == nullptr)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    //initialisera glad (ja e glad för jag vann på lotto!!!!) (connects opengl functiosn)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);

    // while the user does not want to quit, (x button, alt f4)
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window); // Uhmmmmm????+
        glfwPollEvents(); //uhmmmm???
    }

    glfwTerminate();
    return 0;
}