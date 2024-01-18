//2D中原点
#include "originitem.h"

originitem::originitem(QGraphicsItem *parent):
    number(0)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

}
void originitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->setPen(Qt::blue);
    //painter->setBrush(Qt::blue);
    painter->drawEllipse(-3,-3,6,6);
    painter->drawLine(-3,0,3,0);
    painter->drawLine(0,-3,0,3);

}

QRectF originitem::boundingRect() const
{
    return QRectF(-3,-3,6,6);
}

void originitem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = event->pos();
    moveBy(point.x(), point.y());
    emit originsignals(pos(),number);
}

void originitem::setnumber(int n)
{
    number=n;
}
