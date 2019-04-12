/*
 * Author: Jonathan Baird
 * Date: January 2019
 * Email: 006228153@coyote.csusb.edu
 */

#ifndef TURNSIGNAL_H
#define TURNSIGNAL_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>

class TurnSignal : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 1};
    TurnSignal(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const;

public slots:
     void nextFrame();

private:
    int currentFrame;
    QPixmap iPixMap;

};

#endif // TURNSIGNAL_H
