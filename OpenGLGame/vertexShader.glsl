#version 330 core
layout (location = 0) in vec3 aPos;
out vec4 pixelColor;
void main()
{
    gl_Position = vec4(aPos.xyz, 1.0);
    pixelColor = vec4(1.0, 0.0, 0.0, 1.0);
}