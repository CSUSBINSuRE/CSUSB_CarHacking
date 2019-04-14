#include "datatextthreec.h"

DataTextThreeC::DataTextThreeC(QGraphicsItem *parent): QGraphicsTextItem(parent){

    setPlainText(QString("0.889952     215     BB FG HE XA YB FS      FF      .  .... ."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}
