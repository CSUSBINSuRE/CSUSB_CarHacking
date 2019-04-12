#include "backgrounditem.h"

#include <QGraphicsPixmapItem>

BackgroundItem::BackgroundItem(const QPixmap &pixmap, QGraphicsItem * parent): QGraphicsPixmapItem(pixmap, parent){

}

QPainterPath BackgroundItem::shape() const{

    return QPainterPath();
}

