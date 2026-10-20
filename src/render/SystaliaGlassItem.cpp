#include "SystaliaGlassItem.hpp"

#include "SystaliaGlassMaterial.hpp"

#include <QtGui/QImage>
#include <QtQuick/QQuickWindow>
#include <QtQuick/QSGGeometry>
#include <QtQuick/QSGGeometryNode>
#include <QtQuick/QSGTextureProvider>

SystaliaGlassItem::SystaliaGlassItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(ItemHasContents, true);
}

void SystaliaGlassItem::setBackdropSource(QQuickItem *source)
{
    if (m_backdropSource == source)
        return;
    m_backdropSource = source;
    emit backdropSourceChanged();
    update();
}

void SystaliaGlassItem::setThemeMode(int value)
{
    value = qBound(0, value, 1);
    if (m_themeMode == value)
        return;
    m_themeMode = value;
    emit themeModeChanged();
    update();
}

void SystaliaGlassItem::setBlurRadius(qreal value)
{
    value = qBound<qreal>(0.0, value, 48.0);
    if (qFuzzyCompare(m_blurRadius, value))
        return;
    m_blurRadius = value;
    emit blurRadiusChanged();
    update();
}

void SystaliaGlassItem::setBlurIterations(int value)
{
    value = qBound(1, value, 8);
    if (m_blurIterations == value)
        return;
    m_blurIterations = value;
    emit blurIterationsChanged();
    update();
}

void SystaliaGlassItem::setCausticIntensity(qreal value)
{
    value = qBound<qreal>(0.0, value, 2.0);
    if (qFuzzyCompare(m_causticIntensity, value))
        return;
    m_causticIntensity = value;
    emit causticIntensityChanged();
    update();
}

void SystaliaGlassItem::setCornerRadius(qreal value)
{
    value = qBound<qreal>(8.0, value, 160.0);
    if (qFuzzyCompare(m_cornerRadius, value))
        return;
    m_cornerRadius = value;
    emit cornerRadiusChanged();
    update();
}

void SystaliaGlassItem::setAccentColor(const QColor &value)
{
    if (m_accentColor == value)
        return;
    m_accentColor = value;
    emit accentColorChanged();
    update();
}

void SystaliaGlassItem::setTime(qreal value)
{
    if (qFuzzyCompare(m_time, value))
        return;
    m_time = value;
    emit timeChanged();
    update();
}

void SystaliaGlassItem::geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    QQuickItem::geometryChange(newGeometry, oldGeometry);
    update();
}

QSGNode *SystaliaGlassItem::updatePaintNode(QSGNode *oldNode,
                                            UpdatePaintNodeData *updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData);

    auto *node = static_cast<QSGGeometryNode *>(oldNode);
    if (!node) {
        auto *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), 4);
        geometry->setDrawingMode(QSGGeometry::DrawTriangleStrip);
        geometry->setVertexDataPattern(QSGGeometry::StaticPattern);

        auto *vertices = geometry->vertexDataAsTexturedPoint2D();
        vertices[0].set(0.0f, 0.0f, 0.0f, 0.0f);
        vertices[1].set(1.0f, 0.0f, 1.0f, 0.0f);
        vertices[2].set(0.0f, 1.0f, 0.0f, 1.0f);
        vertices[3].set(1.0f, 1.0f, 1.0f, 1.0f);

        node = new QSGGeometryNode;
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry, true);
        node->setMaterial(new SystaliaGlassMaterial);
        node->setFlag(QSGNode::OwnsMaterial, true);
    }

    auto *geometry = node->geometry();
    geometry->setVertexDataPattern(QSGGeometry::DynamicPattern);
    auto *vertices = geometry->vertexDataAsTexturedPoint2D();
    vertices[0].set(0.0f, 0.0f, 0.0f, 0.0f);
    vertices[1].set(static_cast<float>(width()), 0.0f, 1.0f, 0.0f);
    vertices[2].set(0.0f, static_cast<float>(height()), 0.0f, 1.0f);
    vertices[3].set(static_cast<float>(width()), static_cast<float>(height()), 1.0f, 1.0f);

    auto *material = static_cast<SystaliaGlassMaterial *>(node->material());
    SystaliaGlassMaterial::Parameters parameters;
    parameters.windowSize = QSizeF(width(), height());
    parameters.cornerRadius = m_cornerRadius;
    parameters.themeMode = m_themeMode;
    parameters.causticIntensity = m_causticIntensity;
    parameters.accentColor = m_accentColor;
    parameters.time = m_time;
    parameters.blurRadius = m_blurRadius;
    parameters.blurIterations = m_blurIterations;
    material->setParameters(parameters);

    QSGTexture *backdropTexture = nullptr;
    if (m_backdropSource) {
        if (QSGTextureProvider *provider = m_backdropSource->textureProvider())
            backdropTexture = provider->texture();
    }

    if (!backdropTexture && !material->backdropTexture() && window()) {
        QImage fallbackImage(2, 2, QImage::Format_RGBA8888);
        fallbackImage.fill(QColor(QStringLiteral("#101827")));
        QSGTexture *fallbackTexture = window()->createTextureFromImage(fallbackImage);
        fallbackTexture->setFiltering(QSGTexture::Linear);
        material->setFallbackTexture(fallbackTexture);
    }
    material->setBackdropTexture(backdropTexture);

    node->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);
    return node;
}
