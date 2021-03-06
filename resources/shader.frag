#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragCol;
layout(location = 1) in vec2 fragTexCoord;

layout(location = 0) out vec4 outCol;

layout(binding = 1) uniform sampler2D texSampler;

void main() {
    outCol = texture(texSampler, fragTexCoord);
}