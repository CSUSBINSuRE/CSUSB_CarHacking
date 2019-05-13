#include "datatextfive.h"

DataTextFive::DataTextFive(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("0.231765    212     AB FG    XA YB FS ER FF      ....#..."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
