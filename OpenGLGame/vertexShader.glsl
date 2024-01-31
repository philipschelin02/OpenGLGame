#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
uniform float offSet;
out vec4 vertexColor;
void main()
{
    gl_Position = vec4(aPos.xyz, 1.0) + vec4(offSet, 0, 0, 0);
    vertexColor = aCol;
}