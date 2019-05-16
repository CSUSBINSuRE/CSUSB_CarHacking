#include "datatext.h"

DataText::DataText(QGraphicsItem *parent): QGraphicsTextItem(parent){


}

void DataText::DataTextOne(){

    setPlainText(QString("0.978841     215     AB FG HE XA YB FS      FF      ....#..."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));

}

void DataText::DataTextOneC(){

    setPlainText(QString("0.889952     215     AB FG HE XA YB FS      FF      .  .... ."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}

void DataText::DataTextOneWhite(){

    setPlainText(QString("F5"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}

void DataText::DataTextOneRed(){

    setPlainText(QString("F4"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}

void DataText::EndRedOne(){

    setPlainText(QString(" #    , "));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}

void DataText::DataTextTwo(){

    setPlainText(QString("0.572632     313     AA EF XL HG       S7 LH P5      .)......"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}

void DataText::DataTextTwoC(){

    setPlainText(QString("0.325810     313     AA EF XL HG       S7 LH P5      ......  ."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}

void DataText::DataTextTwoWhite(){

    setPlainText(QString("Z3"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",15));
}

void DataText::DataTextTwoRed(){

    setPlainText(QString("6A"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}

void DataText::EndRedTwo(){

    setPlainText(QString(")"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}



