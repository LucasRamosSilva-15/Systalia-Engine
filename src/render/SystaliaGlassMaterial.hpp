#pragma once

#include <QtCore/QSizeF>
#include <QtGui/QColor>
#include <QtQuick/QSGMaterial>

class QSGTexture;

class SystaliaGlassMaterial final : public QSGMaterial
{
public:
    struct Parameters
    {
        QSizeF windowSize;
        qreal cornerRadius = 42.0;
        int themeMode = 0;
        qreal causticIntensity = 0.72;
        QColor accentColor = QColor(QStringLiteral("#00E5FF"));
        qreal time = 0.0;
        qreal blurRadius = 16.0;
        qreal blurIterations = 4.0;
    };

    SystaliaGlassMaterial();
    ~SystaliaGlassMaterial() override;

    [[nodiscard]] QSGMaterialType *type() const override;
    [[nodiscard]] QSGMaterialShader *createShader(QSGRendererInterface::RenderMode renderMode) const override;
    [[nodiscard]] int compare(const QSGMaterial *other) const override;

    void setParameters(const Parameters &parameters);
    [[nodiscard]] const Parameters &parameters() const { return m_parameters; }

    void setBackdropTexture(QSGTexture *texture);
    void setFallbackTexture(QSGTexture *texture);
    [[nodiscard]] QSGTexture *backdropTexture() const { return m_backdropTexture; }

private:
    Parameters m_parameters;
    QSGTexture *m_backdropTexture = nullptr;
    QSGTexture *m_fallbackTexture = nullptr;
};
