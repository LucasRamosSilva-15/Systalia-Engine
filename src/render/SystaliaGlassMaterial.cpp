#include "SystaliaGlassMaterial.hpp"

#include <QtCore/QByteArray>
#include <QtGui/QMatrix4x4>
#include <QtQuick/QSGTexture>

#include <algorithm>
#include <cstring>

namespace {

constexpr qsizetype UniformBlockSize = 124;
constexpr qsizetype OpacityOffset = 64;
constexpr qsizetype WindowSizeOffset = 72;
constexpr qsizetype CornerRadiusOffset = 80;
constexpr qsizetype ThemeModeOffset = 84;
constexpr qsizetype CausticIntensityOffset = 88;
constexpr qsizetype AccentColorOffset = 96;
constexpr qsizetype TimeOffset = 112;
constexpr qsizetype BlurRadiusOffset = 116;
constexpr qsizetype IterationsOffset = 120;

class SystaliaGlassShader final : public QSGMaterialShader
{
public:
    SystaliaGlassShader()
    {
        setShaderFileName(VertexStage, QStringLiteral(":/systalia/shaders/valo_glass.vert.qsb"));
        setShaderFileName(FragmentStage, QStringLiteral(":/systalia/shaders/valo_glass.frag.qsb"));
    }

    bool updateUniformData(RenderState &state,
                           QSGMaterial *newMaterial,
                           QSGMaterial *oldMaterial) override
    {
        Q_UNUSED(oldMaterial);

        auto *material = static_cast<SystaliaGlassMaterial *>(newMaterial);
        QByteArray *uniformData = state.uniformData();
        if (!uniformData || !material)
            return false;

        if (uniformData->size() < UniformBlockSize)
            uniformData->resize(UniformBlockSize);

        const QMatrix4x4 matrix = state.combinedMatrix();
        std::memcpy(uniformData->data(), matrix.constData(), sizeof(float) * 16);

        const SystaliaGlassMaterial::Parameters &parameters = material->parameters();
        const float opacity = state.opacity();
        const float windowWidth = static_cast<float>(std::max<qreal>(parameters.windowSize.width(), 1.0));
        const float windowHeight = static_cast<float>(std::max<qreal>(parameters.windowSize.height(), 1.0));
        const float cornerRadius = static_cast<float>(parameters.cornerRadius);
        const int themeMode = parameters.themeMode;
        const float causticIntensity = static_cast<float>(parameters.causticIntensity);
        const float time = static_cast<float>(parameters.time);
        const float blurRadius = static_cast<float>(parameters.blurRadius);
        const float iterations = static_cast<float>(parameters.blurIterations);
        const float accentColor[4] = {
            parameters.accentColor.redF(),
            parameters.accentColor.greenF(),
            parameters.accentColor.blueF(),
            parameters.accentColor.alphaF(),
        };

        std::memcpy(uniformData->data() + OpacityOffset, &opacity, sizeof(opacity));
        const float windowSize[2] = { windowWidth, windowHeight };
        std::memcpy(uniformData->data() + WindowSizeOffset, windowSize, sizeof(windowSize));
        std::memcpy(uniformData->data() + CornerRadiusOffset, &cornerRadius, sizeof(cornerRadius));
        std::memcpy(uniformData->data() + ThemeModeOffset, &themeMode, sizeof(themeMode));
        std::memcpy(uniformData->data() + CausticIntensityOffset, &causticIntensity, sizeof(causticIntensity));
        std::memcpy(uniformData->data() + AccentColorOffset, accentColor, sizeof(accentColor));
        std::memcpy(uniformData->data() + TimeOffset, &time, sizeof(time));
        std::memcpy(uniformData->data() + BlurRadiusOffset, &blurRadius, sizeof(blurRadius));
        std::memcpy(uniformData->data() + IterationsOffset, &iterations, sizeof(iterations));

        return true;
    }

    void updateSampledImage(RenderState &state,
                            int binding,
                            QSGTexture **texture,
                            QSGMaterial *newMaterial,
                            QSGMaterial *oldMaterial) override
    {
        Q_UNUSED(state);
        Q_UNUSED(oldMaterial);

        if (binding != 1 || !texture || !newMaterial)
            return;

        const auto *material = static_cast<const SystaliaGlassMaterial *>(newMaterial);
        *texture = material->backdropTexture();
    }
};

} // namespace

SystaliaGlassMaterial::SystaliaGlassMaterial()
{
    setFlag(QSGMaterial::Blending);
    setFlag(QSGMaterial::NoBatching);
}

SystaliaGlassMaterial::~SystaliaGlassMaterial()
{
    delete m_fallbackTexture;
}

QSGMaterialType *SystaliaGlassMaterial::type() const
{
    static QSGMaterialType materialType;
    return &materialType;
}

QSGMaterialShader *SystaliaGlassMaterial::createShader(QSGRendererInterface::RenderMode renderMode) const
{
    Q_UNUSED(renderMode);
    return new SystaliaGlassShader;
}

int SystaliaGlassMaterial::compare(const QSGMaterial *other) const
{
    if (!other || other->type() != type())
        return -1;
    return 0;
}

void SystaliaGlassMaterial::setParameters(const Parameters &parameters)
{
    m_parameters = parameters;
}

void SystaliaGlassMaterial::setBackdropTexture(QSGTexture *texture)
{
    m_backdropTexture = texture ? texture : m_fallbackTexture;
}

void SystaliaGlassMaterial::setFallbackTexture(QSGTexture *texture)
{
    if (m_fallbackTexture == texture)
        return;

    delete m_fallbackTexture;
    m_fallbackTexture = texture;
    if (!m_backdropTexture)
        m_backdropTexture = m_fallbackTexture;
}
