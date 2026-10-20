#version 450

layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;
    vec2 u_WindowSize;
    float u_CornerRadius;
    int u_ThemeMode;
    float u_CausticIntensity;
    vec4 u_AccentColor;
    float u_Time;
    float u_BlurRadius;
    float u_Iterations;
} ubuf;

layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec2 aTexCoord;
layout(location = 0) out vec2 vTexCoord;

void main()
{
    gl_Position = ubuf.qt_Matrix * vec4(aPosition, 0.0, 1.0);
    vTexCoord = aTexCoord;
}
