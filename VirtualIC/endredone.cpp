#include "endredone.h"

EndRedOne::EndRedOne(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString(" #    , "));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
