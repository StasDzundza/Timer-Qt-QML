#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QQuickItem>
#include <QTimer>
#include <QTime>
#include <QtMultimedia/QSound>

class Timer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString timeLeftText READ timeLeftText WRITE setTimeLeftText NOTIFY timeLeftTextChanged)
    Q_PROPERTY(bool isActive READ isActive WRITE setIsActive NOTIFY isActiveChanged)

public:
    explicit Timer(QObject *parent = nullptr);
    Q_INVOKABLE void turnOnOf();
    Q_INVOKABLE void reset();
    Q_INVOKABLE void loadTime();
    Q_INVOKABLE void saveTime();

    QString timeLeftText() const;
    void setTimeLeftText(const QString &timeLeftText);

    bool isActive() const;
    void setIsActive(bool isActive);

private slots:
    void checkForTimeout();

signals:
    void isActiveChanged(bool);
    void timeLeftTextChanged(QString);
    void timeout();

private:
    bool m_isActive = false;
    int m_currentTimerTimeMsec = 0;
    QString m_timeLeftText = "Time";

    QTimer m_timer;

    QTime m_timeOnStopwatch;//time which is on the stopwatch
    QTime m_lastStartTime;//time of last start stopwatch

    const QString BEEP_RESOURCE_PATH = "qrc:/sound/beep.wav";
    QSound m_alarmSound;
};

#endif // TIMER_H
