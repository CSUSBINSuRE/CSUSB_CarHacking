#include "datatexttwo.h"

DataTextTwo::DataTextTwo(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("0.572632     313     AA EF XL HG       S7 LH P5      .)......"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
