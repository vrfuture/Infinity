#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec4 aTexcoord;

out vec4 vTexcoord;

void main()
{
	gl_Position = vec4(aPos, 1.0);
	vTexcoord = aTexcoord;
}