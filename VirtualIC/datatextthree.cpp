#include "datatextthree.h"

DataTextThree::DataTextThree(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("0.978841     215     BB FG HE XA YB FS      FF      ....#..."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
