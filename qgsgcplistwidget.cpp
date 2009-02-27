/***************************************************************************
    qgsgcplistwidget.cpp - Widget for GCP list display
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
/* $Id */

#include "qgsgcplistwidget.h"
#include "qgsgcplistmodel.h"

QgsGCPListWidget::QgsGCPListWidget(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  initialize();
}

void QgsGCPListWidget::initialize()
{
  mGCPListModel = new QgsGCPListModel;
  mGCPTableView->setModel(mGCPListModel);
  //mGCPTableView->
}

void QgsGCPListWidget::setGCPList(QgsGCPList *gcpList)
{
  mGCPListModel->setGCPList(gcpList);
}


