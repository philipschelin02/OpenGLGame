#version 330 core
out vec4 pixelColor;
uniform vec4 tintColor;
void main()
{                  //  r     g     b     a
    pixelColor = tintColor;
}