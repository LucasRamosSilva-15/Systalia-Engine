#pragma once

#include "core/EngineConfig.hpp"

#include <QtGui/QColor>
#include <QtQuick/QQuickItem>

class QSGTexture;

class SystaliaGlassItem : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QQuickItem *backdropSource READ backdropSource WRITE setBackdropSource NOTIFY backdropSourceChanged)
    Q_PROPERTY(int themeMode READ themeMode WRITE setThemeMode NOTIFY themeModeChanged)
    Q_PROPERTY(qreal blurRadius READ blurRadius WRITE setBlurRadius NOTIFY blurRadiusChanged)
    Q_PROPERTY(int blurIterations READ blurIterations WRITE setBlurIterations NOTIFY blurIterationsChanged)
    Q_PROPERTY(qreal causticIntensity READ causticIntensity WRITE setCausticIntensity NOTIFY causticIntensityChanged)
    Q_PROPERTY(qreal cornerRadius READ cornerRadius WRITE setCornerRadius NOTIFY cornerRadiusChanged)
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(qreal time READ time WRITE setTime NOTIFY timeChanged)

public:
    explicit SystaliaGlassItem(QQuickItem *parent = nullptr);

    [[nodiscard]] QQuickItem *backdropSource() const { return m_backdropSource; }
    [[nodiscard]] int themeMode() const { return m_themeMode; }
    [[nodiscard]] qreal blurRadius() const { return m_blurRadius; }
    [[nodiscard]] int blurIterations() const { return m_blurIterations; }
    [[nodiscard]] qreal causticIntensity() const { return m_causticIntensity; }
    [[nodiscard]] qreal cornerRadius() const { return m_cornerRadius; }
    [[nodiscard]] QColor accentColor() const { return m_accentColor; }
    [[nodiscard]] qreal time() const { return m_time; }

public slots:
    void setBackdropSource(QQuickItem *source);
    void setThemeMode(int value);
    void setBlurRadius(qreal value);
    void setBlurIterations(int value);
    void setCausticIntensity(qreal value);
    void setCornerRadius(qreal value);
    void setAccentColor(const QColor &value);
    void setTime(qreal value);

signals:
    void backdropSourceChanged();
    void themeModeChanged();
    void blurRadiusChanged();
    void blurIterationsChanged();
    void causticIntensityChanged();
    void cornerRadiusChanged();
    void accentColorChanged();
    void timeChanged();

protected:
    void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData) override;

private:
    QQuickItem *m_backdropSource = nullptr;
    int m_themeMode = EngineConfig::Valo;
    qreal m_blurRadius = 16.0;
    int m_blurIterations = 4;
    qreal m_causticIntensity = 0.72;
    qreal m_cornerRadius = 42.0;
    QColor m_accentColor = QColor(QStringLiteral("#00E5FF"));
    qreal m_time = 0.0;
};
