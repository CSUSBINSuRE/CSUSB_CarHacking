#include "datatextfour.h"

DataTextFour::DataTextFour(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("0.978841     215     AB FG HE XA YB FS      FF      ....#..."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
