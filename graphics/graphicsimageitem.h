#ifndef GRAPHICSIMAGEITEM_H
#define GRAPHICSIMAGEITEM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QHoverEvent>
class graphicsimageitem:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    graphicsimageitem();
    graphicsimageitem(QPixmap pix);
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
protected:
//
 signals:
    void mousemove(qreal scale,QPointF info);
};

#endif // GRAPHICSIMAGEITEM_H
