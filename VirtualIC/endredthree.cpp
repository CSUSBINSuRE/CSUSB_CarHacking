#include "endredthree.h"

EndRedThree::EndRedThree(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString(" #    , "));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}
