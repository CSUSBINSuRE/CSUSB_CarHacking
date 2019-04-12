#include "endredtwo.h"

EndRedTwo::EndRedTwo(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString(")"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
