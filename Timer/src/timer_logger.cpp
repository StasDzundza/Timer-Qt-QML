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
    writeToFile("The following time has been loaded : " + loadedTime + " from file \""
                + fileName + "\"\n\n");
}

void TimerLogger::saveEventLog(const QString &timerTime, const QAbstractListModel *timeMomentsModel,const QString& filePath)
{
    QString logInfo = "The following time has been saved: " + timerTime + "\n";
    int rowCount = timeMomentsModel->rowCount();
    if(rowCount > 0){
        logInfo.append("Saved time moments:\n");
        for(int i = 0; i < rowCount; i++){
            logInfo.append(QString::number(i + 1) + ")" + timeMomentsModel->index(i).data(Qt::DisplayRole).toString() + "\n");
        }
    }
    logInfo.append("\n\n");
    writeToFile(logInfo);
    writeToConcretteFile(logInfo, filePath);
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

void TimerLogger::infoLog(const QString &infoMessage, const QString &fileName)
{
    writeToConcretteFile(infoMessage, fileName);
}

void TimerLogger::writeToFile(const QString & text)
{
    writeToConcretteFile(text, LOG_FILE_NAME);
}

void TimerLogger::writeToConcretteFile(const QString &text, const QString &fileName)
{
    QFile logFile(fileName);
    logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream stream(&logFile);
    stream << text;
    logFile.close();
}
