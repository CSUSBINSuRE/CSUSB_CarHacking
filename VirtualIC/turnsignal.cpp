/*
 * Author: Jonathan Baird
 * Date: January 2019
 * Email: 006228153@coyote.csusb.edu
 */

#include "turnsignal.h"
#include <QPainter>

TurnSignal::TurnSignal(QGraphicsItem *parent): QGraphicsItem(parent) ,currentFrame() {

    setFlag(ItemClipsToShape);
    iPixMap = QPixmap(":/images_root/blinkAnimationLfixed2.png");

    QTimer *timer = new QTimer(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));

    timer->start(100);
}

void TurnSignal::nextFrame(){

    currentFrame += 47;
    if (currentFrame >= 1074) {
        currentFrame = 0;
    }
}

QRectF TurnSignal::boundingRect() const {

    return QRectF(0,0,39,36);
}

void TurnSignal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->drawPixmap(0,0, iPixMap, currentFrame, 0,39,36);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

int TurnSignal::type() const {

    return Type;
}
