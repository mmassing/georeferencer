/***************************************************************************
    qgsgcplistmodel.h - Model implementation of GCPList Model/View
     --------------------------------------
    Date                 : 27-Feb-2009
    Copyright            : (c) 2009 by Manuel Massing
    Email                : m.massing at warped-space.de
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSGCP_LIST_TABLE_VIEW_H
#define QGSGCP_LIST_TABLE_VIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include "qgsgcplist.h"
#include "qgsgeorefdatapoint.h"


class QgsGCPListModel : public QStandardItemModel {
  //Q_OBJECT
public:
  QgsGCPListModel(QObject *parent = NULL);
  
  void setGCPList(QgsGCPList *theGCPList)
  {
    mGCPList = theGCPList;
    clear();

    // Setup table header
    QStringList itemLabels;
    itemLabels<<"id"<<"srcX"<<"srcY"<<"dstX"<<"dstY";
    setHorizontalHeaderLabels(itemLabels);

    setRowCount(mGCPList->size());
    setColumnCount(5);

    for (int i = 0; i < mGCPList->size(); i++) {
      int j = 0;
      QgsGeorefDataPoint &p = *(*mGCPList)[i];
         
      setItem(i, j++, new QStandardItem(QString("%1").arg( i )));
      setItem(i, j++, new QStandardItem(QString("%1").arg( p.pixelCoords().x() )));
      setItem(i, j++, new QStandardItem(QString("%1").arg(-p.pixelCoords().y() )));
      setItem(i, j++, new QStandardItem(QString("%1").arg( p.mapCoords().x()   )));
      setItem(i, j++, new QStandardItem(QString("%1").arg( p.mapCoords().y()   )));
    }
    
    reset(); // Signal to views that the model has changed
  }  
protected:
  QgsGCPList *mGCPList;
};

#endif