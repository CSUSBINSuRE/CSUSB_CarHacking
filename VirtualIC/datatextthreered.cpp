#include "datatextthreered.h"

DataTextThreeRed::DataTextThreeRed(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("D7"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
