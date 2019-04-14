#include "datatextthreewhite.h"

DataTextThreeWhite::DataTextThreeWhite(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("D6"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
