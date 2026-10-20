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

layout(binding = 1) uniform sampler2D u_Backdrop;
layout(location = 0) in vec2 vTexCoord;
layout(location = 0) out vec4 fragColor;

float sdSquircle(vec2 point, vec2 halfSize, float radius)
{
    vec2 core = max(halfSize - vec2(radius), vec2(0.0));
    vec2 q = abs(point) - core;
    vec2 positive = max(q, vec2(0.0));
    float superellipse = pow(pow(positive.x, 4.0) + pow(positive.y, 4.0), 0.25);
    float inside = min(max(q.x, q.y), 0.0) - radius;
    float outside = superellipse - radius;
    return max(q.x, q.y) > 0.0 ? outside : inside;
}

float squircleMask(vec2 uv)
{
    vec2 point = (uv - 0.5) * ubuf.u_WindowSize;
    vec2 halfSize = ubuf.u_WindowSize * 0.5;
    float distanceToEdge = sdSquircle(point, halfSize, ubuf.u_CornerRadius);
    float antialias = max(fwidth(distanceToEdge), 0.75);
    return 1.0 - smoothstep(-antialias, antialias, distanceToEdge);
}

vec4 sampleBlurredBackdrop(vec2 uv)
{
    vec2 texel = 1.0 / max(ubuf.u_WindowSize, vec2(1.0));
    float radius = max(ubuf.u_BlurRadius, 0.0);
    vec2 diagonal = vec2(0.70710678);
    vec2 offsets[8] = vec2[](
        vec2(1.0, 0.0), vec2(-1.0, 0.0),
        vec2(0.0, 1.0), vec2(0.0, -1.0),
        diagonal, -diagonal,
        vec2(diagonal.x, -diagonal.y), vec2(-diagonal.x, diagonal.y)
    );

    vec4 result = texture(u_Backdrop, uv) * 0.28;
    float samples = 0.28;
    int iterations = clamp(int(ubuf.u_Iterations + 0.5), 1, 8);
    for (int i = 0; i < 8; ++i) {
        if (i >= iterations * 2)
            break;
        float scale = radius * (0.75 + float(i % 2) * 0.5);
        result += texture(u_Backdrop, uv + offsets[i] * texel * scale) * 0.09;
        samples += 0.09;
    }
    return result / samples;
}

float hash21(vec2 point)
{
    point = fract(point * vec2(123.34, 456.21));
    point += dot(point, point + 45.32);
    return fract(point.x * point.y);
}

float mistNoise(vec2 point)
{
    vec2 cell = floor(point);
    vec2 local = smoothstep(0.0, 1.0, fract(point));
    float a = hash21(cell);
    float b = hash21(cell + vec2(1.0, 0.0));
    float c = hash21(cell + vec2(0.0, 1.0));
    float d = hash21(cell + vec2(1.0, 1.0));
    return mix(mix(a, b, local.x), mix(c, d, local.x), local.y);
}

vec3 valoOptics(vec2 uv, vec3 backdrop)
{
    vec2 centered = uv - 0.5;

    // Smooth 45-degree caustic glare across the chassis.
    float diag = (uv.x + (1.0 - uv.y)) * 0.5;
    float causticSheen = smoothstep(0.2, 0.8, diag)
        * 0.25
        * ubuf.u_CausticIntensity;

    // Specular top-edge refraction.
    float topRim = smoothstep(0.04, 0.0, uv.y) * 0.45;
    float caustic = causticSheen + topRim * ubuf.u_CausticIntensity;
    float wave = 0.5 + 0.5 * sin((centered.x + centered.y) * 42.0 + ubuf.u_Time * 2.8);
    float edge = smoothstep(0.40, 0.72, length(centered));
    vec3 dispersion = vec3(caustic * 1.20, caustic * (0.55 + wave * 0.25), caustic * 0.36);
    vec3 cyanEdge = ubuf.u_AccentColor.rgb * edge * 0.22;
    return backdrop * vec3(1.05, 1.02, 1.08) + dispersion + cyanEdge;
}

vec3 soarMist(vec2 uv, vec3 backdrop)
{
    float mist = mistNoise(uv * 7.0 + vec2(ubuf.u_Time * 0.08, -ubuf.u_Time * 0.04));
    mist = smoothstep(0.22, 0.88, mist);
    vec3 neutralFog = vec3(0.78, 0.86, 0.91) * (0.08 + mist * 0.14);
    vec3 accentFog = ubuf.u_AccentColor.rgb * mist * 0.10;
    return mix(backdrop, backdrop + neutralFog + accentFog, 0.48);
}

void main()
{
    float mask = squircleMask(vTexCoord);
    if (mask <= 0.001)
        discard;

    vec4 source = sampleBlurredBackdrop(vTexCoord);
    vec3 glassColor = ubuf.u_ThemeMode == 0
        ? valoOptics(vTexCoord, source.rgb)
        : soarMist(vTexCoord, source.rgb);

    float interior = ubuf.u_ThemeMode == 0 ? 0.20 : 0.13;
    float alpha = mask * ubuf.qt_Opacity * (0.58 + interior);
    fragColor = vec4(glassColor, alpha);
}
