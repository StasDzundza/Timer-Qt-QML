#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <vector>
#include <QAbstractListModel>

class TimerLogger
{
public:
    static void startEventLog(const QString&);
    static void pauseEventLog(const QString&);
    static void resetEventLog(const QString&);
    static void loadEventLog(const QString&, const QString&);
    static void saveEventLog(const QString&, const QAbstractListModel*,const QString&);
    static void setTimeEventLog(const QString&);
    static void errorEventLog(const QString&);
    static void infoLog(const QString&);
    static void infoLog(const QString&, const QString&);

private:
    static void writeToFile(const QString&);
    static void writeToConcretteFile(const QString&, const QString&);

    static const QString LOG_FILE_NAME;
};

#endif // LOGGER_H
