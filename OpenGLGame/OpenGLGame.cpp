#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow*);

void error_callback(int error, const char* msg) {
    string s;
    s = " [" + to_string(error) + "] " + msg + '\n';
    cerr << s << endl;
}

struct Window {
    void Render() {

    }
};

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

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    //init ends here
    //real program starts here!!!!!!
    float red = 0;

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //creates array buffer on gpu
    float vertices[] = { //the vertices here are essentially points. Triangles obviously have three points. 
        //The vertices have to be at the right distance. Otherwise the triangle will look weird and stretched
     //triangle ett

        //The coords have to be between 1f and -1f. Think of them as being part of a typical coordinate system. kinda smart way to think tbh

    -0.9f, 0.0f, 0.0f, //vertice uno
     0.0f, 0.0f, 0.0f, //vertice dos
     -0.45f,  0.5f, 0.0f, //vertice tres
    };
    // Variable to store buffer id

    unsigned int VBO;
    glGenBuffers(1, &VBO); // ask open gl to create bufferie!!!!
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //tell gl to use this buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //copy vertices to buffer


    //configure vertex attributes currently theres just one, namely the positions
    //so vertex understands where to find the input attributes, posotion in this case
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int VAO2;
    glGenVertexArrays(1, &VAO2);
    glBindVertexArray(VAO2);

    //creates array buffer on gpu
    float vertices2[] = { //the vertices here are essentially points. Triangles obviously have three points. 
        //The vertices have to be at the right distance. Otherwise the triangle will look weird and stretched
     //triangle ett

        //The coords have to be between 1f and -1f. Think of them as being part of a typical coordinate system. kinda smart way to think tbh

    //triangle två
     0.0f, -0.0f, 0.0f,
     0.45f, 0.5f, 0.0f,
     0.9f,  0.0f, 0.0f
    };
    // Variable to store buffer id

    unsigned int VBO2;
    glGenBuffers(1, &VBO2); // ask open gl to create bufferie!!!!
    glBindBuffer(GL_ARRAY_BUFFER, VBO2); //tell gl to use this buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW); //copy vertices to buffer


    //configure vertex attributes currently theres just one, namely the positions
    //so vertex understands where to find the input attributes, posotion in this case
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Compile vertex shaderie on gpuie
    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // ------ Compile the Orange Fragment Shader on the GPU --------
    const char* orangeFragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0";
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
    unsigned int yellowFragmentShader;
    yellowFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(yellowFragmentShader, 1, &yellowFragmentShaderSource, NULL);
    glCompileShader(yellowFragmentShader);

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    unsigned int orangeShaderProgram;
    orangeShaderProgram = glCreateProgram();
    glAttachShader(orangeShaderProgram, vertexShader);
    glAttachShader(orangeShaderProgram, orangeFragmentShader);
    glLinkProgram(orangeShaderProgram);

    // -------- Create Yellow Shader Program (Render Pipeline) ---------
    unsigned int yellowShaderProgram;
    yellowShaderProgram = glCreateProgram();
    glAttachShader(yellowShaderProgram, vertexShader);
    glAttachShader(yellowShaderProgram, yellowFragmentShader);
    glLinkProgram(yellowShaderProgram);

    //cleanie uppie shadies!!!!
    glDeleteShader(vertexShader);
    glDeleteShader(orangeFragmentShader);
    glDeleteShader(yellowFragmentShader);
    // while the user does not want to quit, (x button, alt f4)
    while (!glfwWindowShouldClose(window))
    {
        //process input (eg close window on esc)
        glfwPollEvents(); //uhmmmm???
        processInput(window);
        red += 0.001f;
        if (red > 1)
            red -= 1;

        //render (paint current frame of game)
        glClearColor(red, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3); //change 3 to six cuz we doin 6 vertices now
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
    }
    //cleans upp all the glfw stuffies
    glfwTerminate();
    return 0;
}
// Function to process input
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}