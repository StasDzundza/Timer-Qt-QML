#ifndef TIMEMOMENTMODEL_H
#define TIMEMOMENTMODEL_H

#include <QAbstractListModel>
#include <QString>
#include <vector>

class TimeMomentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    TimeMomentModel();

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    void addTimeMoment(const QString& timeMoment);
    void reset();
private:
    std::vector<QString> m_timeMoments;
};

#endif // TIMEMOMENTMODEL_H
