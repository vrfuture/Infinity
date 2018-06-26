#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec4 aTexcoord;

out vec4 vTexcoord;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * vec4(aPos, 1.0);
	vTexcoord = aTexcoord;
}