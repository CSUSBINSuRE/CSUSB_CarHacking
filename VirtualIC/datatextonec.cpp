#include "datatextonec.h"

DataTextOneC::DataTextOneC(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("0.889952     215     AB FG HE XA YB FS      FF      .  .... ."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
