#version 430 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec2 in_tex_coord;

out vec2 texCoord0;

void main(void) {
    gl_Position = in_position;
    texCoord0 = in_tex_coord;
}
