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
    TimeMomentModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void addTimeMoment(const QString& timeMoment);
    Q_INVOKABLE void reset();
private:
    std::vector<QString> m_timeMoments;

    enum TimeRole
    {
        TimeMoment = Qt::UserRole + 1
    };
};

#endif // TIMEMOMENTMODEL_H
