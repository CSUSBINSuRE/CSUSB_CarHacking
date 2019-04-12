#include "datatextonewhite.h"

DataTextOneWhite::DataTextOneWhite(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("F4"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}


