#include "datatextfourwhite.h"

DataTextFourWhite::DataTextFourWhite(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("F4"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
