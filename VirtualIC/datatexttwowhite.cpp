#include "datatexttwowhite.h"

DataTextTwoWhite::DataTextTwoWhite(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("Z3"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
