#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 aTexCoord;
//                                ^ input #2 tex coord
out vec4 vertexColor;
out vec2 texCoord; // we want to output a tex coord

uniform float horizontalOffset;

void main()
{
    gl_Position = vec4(aPos.x + horizontalOffset, aPos.y, aPos.z, 1.0);
    vertexColor = aCol;
    texCoord = aPos.xy; // we do output the value. uv cords start in bottom left
}