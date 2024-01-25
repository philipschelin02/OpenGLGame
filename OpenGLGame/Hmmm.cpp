/*




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

// ------ Compile the Yellow Fragment Shader on the GPU --------
const char* yellowFragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"} \0";
unsigned int yellowFragmentShader{ glCreateShader(GL_FRAGMENT_SHADER) };
glShaderSource(yellowFragmentShader, 1, &yellowFragmentShaderSource, NULL);
glCompileShader(yellowFragmentShader); /*/

//Unsure what to do with this code. Maybe keep around?