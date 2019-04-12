#include "datatextonered.h"

DataTextOneRed::DataTextOneRed(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("X7"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}




