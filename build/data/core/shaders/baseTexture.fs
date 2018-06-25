#version 330 core
out vec4 FragColor;

in vec4 vTexcoord;

uniform sampler2D ourTexture;

void main()
{
    // flip coordinate in y direction to suit soil image load
	FragColor = texture(ourTexture, vec2(vTexcoord.x, 1 - vTexcoord.y));
}