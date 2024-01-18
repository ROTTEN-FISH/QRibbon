#ifndef CIRCLEITEM_H
#define CIRCLEITEM_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPainter>


class CircleItem:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    CircleItem(QGraphicsItem *parent = nullptr);
    QRectF  boundingRect() const;
    void setSize(QRectF new_size,bool fixed);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    //内容框
    QRectF  size,in_size;
    QString FLAG;
    QPointF click_point;
    qreal temp;
    bool f;
protected:
signals:
    void mysignals(int type,QPointF p,QPointF lt,QPointF rt,QPointF lb,QPointF rb,int Rotate);
};

#endif // CIRCLEITEM_H
