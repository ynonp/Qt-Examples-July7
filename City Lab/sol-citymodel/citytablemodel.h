/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CITYTABLEMODEL_H
#define CITYTABLEMODEL_H

#include <QtGui>

class CityEngine;

class CityTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CityTableModel(QObject *parent = 0);
    void setInput(CityEngine *input);
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    int	rowCount ( const QModelIndex & parent = QModelIndex() ) const;

    QVariant data ( const QModelIndex & index,
                    int role = Qt::DisplayRole ) const;

    QVariant headerData ( int section, Qt::Orientation orientation,
                          int role = Qt::DisplayRole ) const;

private:
    CityEngine *m_input;
};

#endif // CITYTABLEMODEL_H
