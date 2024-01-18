#ifndef ORIGINITEM_H
#define ORIGINITEM_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
class originitem :public QObject,public QGraphicsItem
{
    Q_OBJECT;
public:
    originitem(QGraphicsItem *parent = nullptr);
    QRectF  boundingRect() const;
    void setnumber(int n);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int number;
protected:
signals:
    void originsignals(QPointF p,int n);
};

#endif // ORIGINITEM_H
