#include "datatexttwored.h"

DataTextTwoRed::DataTextTwoRed(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("6A"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
