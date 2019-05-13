#include "datatextfourred.h"

DataTextFourRed::DataTextFourRed(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("X7"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
