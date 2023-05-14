#pragma once

#include <QAbstractTableModel>
#include <QString>

class GcodeTblModel final : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit GcodeTblModel(QObject* pParent = nullptr) : QAbstractTableModel{ pParent } { mHeaders << "Command" << "Status";}

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    bool insertRow(int row, const QModelIndex& parent = {});
    bool removeRow(int row, const QModelIndex& parent = {});
    void clear();

    int rowCount(const QModelIndex& parent = {}) const { return mData.size(); }
    int columnCount(const QModelIndex& parent = {}) const { return 2; }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;

private:
    struct GCodeItem final
    {
        QString command;
        QString status;
    };

    QList<GCodeItem*> mData;
    QStringList mHeaders;
};
