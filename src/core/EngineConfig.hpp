#pragma once

#include <QtCore/QObject>
#include <QtGui/QColor>
#include <QtQmlIntegration/qqmlintegration.h>

class EngineConfig : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(ThemeMode themeMode READ themeMode WRITE setThemeMode NOTIFY themeModeChanged)
    Q_PROPERTY(qreal blurRadius READ blurRadius WRITE setBlurRadius NOTIFY blurRadiusChanged)
    Q_PROPERTY(int blurIterations READ blurIterations WRITE setBlurIterations NOTIFY blurIterationsChanged)
    Q_PROPERTY(qreal causticGain READ causticGain WRITE setCausticGain NOTIFY causticGainChanged)
    Q_PROPERTY(qreal cornerRadius READ cornerRadius WRITE setCornerRadius NOTIFY cornerRadiusChanged)
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)

public:
    enum ThemeMode {
        Valo = 0,
        Soar = 1,
    };
    Q_ENUM(ThemeMode)

    explicit EngineConfig(QObject *parent = nullptr)
        : QObject(parent)
    {
    }

    [[nodiscard]] ThemeMode themeMode() const { return m_themeMode; }
    [[nodiscard]] qreal blurRadius() const { return m_blurRadius; }
    [[nodiscard]] int blurIterations() const { return m_blurIterations; }
    [[nodiscard]] qreal causticGain() const { return m_causticGain; }
    [[nodiscard]] qreal cornerRadius() const { return m_cornerRadius; }
    [[nodiscard]] QColor accentColor() const { return m_accentColor; }

public slots:
    void setThemeMode(ThemeMode value)
    {
        if (m_themeMode == value)
            return;
        m_themeMode = value;
        emit themeModeChanged();
    }

    void setBlurRadius(qreal value)
    {
        value = qBound<qreal>(0.0, value, 48.0);
        if (qFuzzyCompare(m_blurRadius, value))
            return;
        m_blurRadius = value;
        emit blurRadiusChanged();
    }

    void setBlurIterations(int value)
    {
        value = qBound(1, value, 8);
        if (m_blurIterations == value)
            return;
        m_blurIterations = value;
        emit blurIterationsChanged();
    }

    void setCausticGain(qreal value)
    {
        value = qBound<qreal>(0.0, value, 2.0);
        if (qFuzzyCompare(m_causticGain, value))
            return;
        m_causticGain = value;
        emit causticGainChanged();
    }

    void setCornerRadius(qreal value)
    {
        value = qBound<qreal>(8.0, value, 160.0);
        if (qFuzzyCompare(m_cornerRadius, value))
            return;
        m_cornerRadius = value;
        emit cornerRadiusChanged();
    }

    void setAccentColor(const QColor &value)
    {
        if (m_accentColor == value)
            return;
        m_accentColor = value;
        emit accentColorChanged();
    }

signals:
    void themeModeChanged();
    void blurRadiusChanged();
    void blurIterationsChanged();
    void causticGainChanged();
    void cornerRadiusChanged();
    void accentColorChanged();

private:
    ThemeMode m_themeMode = Valo;
    qreal m_blurRadius = 16.0;
    int m_blurIterations = 4;
    qreal m_causticGain = 0.72;
    qreal m_cornerRadius = 42.0;
    QColor m_accentColor = QColor(QStringLiteral("#00E5FF"));
};
