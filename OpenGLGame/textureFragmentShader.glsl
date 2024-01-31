#version 330 core

out vec4 pixelColor;

uniform vec4 tintColor;
uniform sampler2D diffuseTexture;

in vec4 vertexColor;
in vec2 texCoord;

void main()
{
    pixelColor = texture(diffuseTexture, texCoord);
}