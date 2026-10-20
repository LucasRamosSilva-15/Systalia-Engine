#version 450

layout(std140, binding = 0) uniform blurParams {
    vec2 u_TexelSize;
    float u_Radius;
    float u_Intensity;
} params;

layout(binding = 1) uniform sampler2D u_Source;
layout(location = 0) in vec2 vTexCoord;
layout(location = 0) out vec4 fragColor;

void main()
{
    vec2 stepSize = params.u_TexelSize * params.u_Radius;
    vec4 result = texture(u_Source, vTexCoord) * 0.40;
    result += texture(u_Source, vTexCoord + vec2(stepSize.x, 0.0)) * 0.15;
    result += texture(u_Source, vTexCoord - vec2(stepSize.x, 0.0)) * 0.15;
    result += texture(u_Source, vTexCoord + vec2(0.0, stepSize.y)) * 0.15;
    result += texture(u_Source, vTexCoord - vec2(0.0, stepSize.y)) * 0.15;
    fragColor = result * params.u_Intensity;
}
