#include "timer.h"
#include <QDebug>

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
}

void Timer::reset()
{
    m_timer.stop();
    m_timeLeftText = "Time";
    m_timeOnStopwatch = QTime::fromMSecsSinceStartOfDay(0);
}

void Timer::loadTime()
{
    m_timeLeftText = "00:05:000";
    //load and check by regular exp
    //we are finding msec from string to int
    QString m,s,ms;
    int mmInt,ssInt, msInt;

    m = m_timeLeftText[0];
    m = m + m_timeLeftText[1];
    mmInt = m.toInt();
    s = m_timeLeftText[3];
    s = s + m_timeLeftText[4];
    ssInt = s.toInt();
    ms = m_timeLeftText[6];
    ms += m_timeLeftText[7];
    ms += m_timeLeftText[8];

    ssInt*=1000;
    mmInt*=60*1000;
    msInt = ms.toInt();

    m_currentTimerTimeMsec = ssInt+mmInt+msInt;//timer time in mseconds
}

void Timer::saveTime()
{
    //save
}

void Timer::checkForTimeout()
{
    int on_stopwatch = m_timeOnStopwatch.msecsSinceStartOfDay() + QTime::currentTime().msecsSinceStartOfDay() - m_lastStartTime.msecsSinceStartOfDay();
    QString time_on_sw_string = QTime::fromMSecsSinceStartOfDay(on_stopwatch).toString("mm:ss:zzz");
    int remine  = m_currentTimerTimeMsec - on_stopwatch;
    qDebug() << remine;
    qDebug() << m_timeLeftText;
    if(remine <= 0){
        m_timer.stop();
        m_timeOnStopwatch = QTime::fromMSecsSinceStartOfDay(0);
        m_timeLeftText = "Time Out";
        emit timeout();
        m_alarmSound.play();
    }
    else{
        m_timeLeftText = QTime::fromMSecsSinceStartOfDay(remine).toString("mm:ss:zzz");
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
