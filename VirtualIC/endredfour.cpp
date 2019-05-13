#include "endredfour.h"

EndRedFour::EndRedFour(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString(" #    , "));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
