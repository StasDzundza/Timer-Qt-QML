#include "timer.h"
#include <QDebug>
#include <QRegularExpression>

Timer::Timer(QObject *parent) : QObject(parent), m_alarmSound(BEEP_RESOURCE_PATH)
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(checkForTimeout()));
}

void Timer::turnOnOf()
{
    //check for time existing
    if(m_timer.isActive()){
        m_timer.stop();
        m_timeOnStopwatch = QTime::fromMSecsSinceStartOfDay(m_timeOnStopwatch.msecsSinceStartOfDay()+QTime::currentTime().msecsSinceStartOfDay()- m_lastStartTime.msecsSinceStartOfDay());
    }
    else{
        m_lastStartTime = QTime::currentTime();
        m_timer.start(1);
    }
    m_isActive = !m_isActive;
    emit isActiveChanged();
}

void Timer::reset()
{
    m_timer.stop();
    m_timeLeftText = "Time";
    emit timeLeftTextChanged();
    m_timeOnStopwatch = QTime::fromMSecsSinceStartOfDay(0);
    m_isTimeSetted = false;
    m_isActive = false;
    emit isActiveChanged();
}

void Timer::loadTime()
{
    QString timeText = "00:05:000";
    setTime(timeText);
}

void Timer::setTime(const QString &textTime)
{
    int msec = textTimeToMsec(textTime);
    if(msec != -1){
        m_currentTimerTimeMsec = msec;
        m_isTimeSetted = true;
        m_timeLeftText = textTime;
        m_timeOnStopwatch = QTime::fromMSecsSinceStartOfDay(0);
    }else{
        m_timeLeftText = "Incorrect time format received";
    }
    emit timeLeftTextChanged();
}

void Timer::saveTime()
{
    //save
}

void Timer::checkForTimeout()
{
    int onTimer = m_timeOnStopwatch.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - m_lastStartTime.msecsSinceStartOfDay();
    int remine = m_currentTimerTimeMsec - onTimer;
    if(remine <= 0){
        m_timer.stop();
        m_timeOnStopwatch = QTime::fromMSecsSinceStartOfDay(0);
        m_timeLeftText = "Time Out";
        emit timeLeftTextChanged();
        m_isTimeSetted = false;
        m_isActive = false;
        emit isActiveChanged();
        emit timeout();
        m_alarmSound.play();
    }
    else{
        m_timeLeftText = QTime::fromMSecsSinceStartOfDay(remine).toString("mm:ss:zzz");
        emit timeLeftTextChanged();
    }
}

bool Timer::isActive() const
{
    return m_isActive;
}

void Timer::setIsActive(bool isActive)
{
    m_isActive = isActive;
}

QString Timer::timeLeftText() const
{
    return m_timeLeftText;
}

void Timer::setTimeLeftText(const QString &timeLeftText)
{
    m_timeLeftText = timeLeftText;
}

int Timer::textTimeToMsec(const QString& textTime){
    if(!isCorrectTimeFormat(textTime)){
        return -1;
    }else{
        QStringList timeUnits = textTime.split(":");
        return timeUnits.at(0).toInt() * 60 * 1000 +
                timeUnits.at(1).toInt() * 1000 +
                timeUnits.at(2).toInt();
    }
}

bool Timer::isCorrectTimeFormat(const QString& textTime){
    QRegularExpression timeFormatRegEx("\\d{1,2}:\\d{1,2}:\\d{1,3}");
    return timeFormatRegEx.match(textTime).hasMatch();
}
