#include "infotext.h"

InfoText::InfoText(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("    Delta         ID                         Data"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}


