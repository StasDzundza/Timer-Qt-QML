#include "timer_logger.h"
#include <QFile>
#include <QTextStream>

const QString TimerLogger::LOG_FILE_NAME = "log_info.log";

void TimerLogger::startEventLog(const QString &startTime)
{
    writeToFile("Timer started work from time : " + startTime + "\n\n");
}

void TimerLogger::pauseEventLog(const QString &pauseTime)
{
    writeToFile("Timer paused work at time : " + pauseTime + "\n\n");
}

void TimerLogger::resetEventLog(const QString &resetTime)
{
    writeToFile("Timer was reseted at time : " + resetTime + "\n\n");
}

void TimerLogger::loadEventLog(const QString &loadedTime, const QString& fileName)
{
    writeToFile("The following time has been loaded : " + loadedTime + "from file \""
                + fileName + "\"\n\n");
}

void TimerLogger::saveEventLog(const QString &timerTime, const std::vector<QString>& timeMoments)
{
    QString logInfo = "The following time has been saved: " + timerTime + "\n";
    if(timeMoments.size() > 0){
        int i = 0;
        logInfo.append("Saved time moments:\n");
        for(QString timeMoment: timeMoments){
            logInfo.append(QString::number(i++) + ")" + " " + timeMoment);
        }
    }
    logInfo.append("\n\n");
    writeToFile(logInfo);
}

void TimerLogger::setTimeEventLog(const QString &settedTime)
{
    writeToFile("The following time has been setted: " + settedTime + "\n\n");
}

void TimerLogger::errorEventLog(const QString &errorMessage)
{
    writeToFile("The following error has been occurred: " + errorMessage + "\n\n");
}

void TimerLogger::infoLog(const QString &infoMessage)
{
    writeToFile(infoMessage + "\n\n");
}

void TimerLogger::writeToFile(const QString & text)
{
    QFile logFile(LOG_FILE_NAME);
    logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream stream(&logFile);
    stream << text;
    logFile.close();
}
