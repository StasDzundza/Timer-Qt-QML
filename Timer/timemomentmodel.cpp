#include "timemomentmodel.h"

TimeMomentModel::TimeMomentModel()
{
}

int TimeMomentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_timeMoments.size();
}

QVariant TimeMomentModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole){
        return {};
    }
    return QVariant::fromValue(m_timeMoments.at(index.row()));
}

void TimeMomentModel::addTimeMoment(const QString &timeMoment)
{
    m_timeMoments.push_back(timeMoment);
    emit dataChanged(createIndex(0, 0), createIndex(m_timeMoments.size(), 0));
}

void TimeMomentModel::reset()
{
    m_timeMoments.clear();
    emit dataChanged(createIndex(0, 0), createIndex(m_timeMoments.size(), 0));
}
