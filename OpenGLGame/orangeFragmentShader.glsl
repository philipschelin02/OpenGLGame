#version 330 core
out vec4 pixelColor;
uniform vec4 tintColor;
in vec4 vertexColor;
void main()
{                  //  r     g     b     a
    pixelColor = vertexColor;
}