#include "gcode_tbl_model.h"


QVariant GcodeTblModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    if (index.row() >= mData.size())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (index.column())
        {
        case 0: return mData.at(index.row())->command;
        case 1: return mData.at(index.row())->status;
        }
    }

    return QVariant();
}

bool GcodeTblModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        switch (index.column())
        {
        case 0: mData.at(index.row())->command = value.toString(); break;
        case 1: mData.at(index.row())->status = value.toString(); break;
        }
        return true;
    }

    return false;
}

bool GcodeTblModel::insertRow(int row, const QModelIndex& parent)
{
    if (row > rowCount())
    {
        return false;
    }

    beginInsertRows(parent, row, row);
    mData.insert(row, new GCodeItem());
    endInsertRows();

    return true;
}

bool GcodeTblModel::removeRow(int row, const QModelIndex& parent)
{
    beginRemoveRows(parent, row, row);
    mData.removeAt(row);
    endRemoveRows();
    return true;
}

void GcodeTblModel::clear()
{
    beginResetModel();

    for (const auto item : mData)
    {
        delete item;
    }
    mData.clear();
    endResetModel();
}

QVariant GcodeTblModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (orientation == Qt::Horizontal)
    {
        return mHeaders.at(section);
    }
    else
    {
        return QString::number(section + 1);
    }
}

Qt::ItemFlags GcodeTblModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
    {
        return {};
    }
    if (index.column() == 0)
    {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }
    else
    {
        return QAbstractTableModel::flags(index);
    }
}
