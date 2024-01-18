#ifndef GRAPHICSIMAGE_H
#define GRAPHICSIMAGE_H
#include<QGraphicsView>
//#include<QGraphicsSceneMouseEvent>
#include<QMouseEvent>
#include<QKeyEvent>
#include<QWheelEvent>
#include <QWidget>
class GraphicsImage:public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsImage(QWidget *parent);
    void wheelEvent(QWheelEvent *event);
//    void mouseEnterEvent(QKeyEvent  *event) ;
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseDoubleClickEvent(QMouseEvent *event);
//    void translate(QPointF delta);
private:
    qreal m_scale=1;
    QPoint m_lastPointF;
    bool mouse_click;
protected:
//
 signals:
    void mousemove(qreal scale,QPointF info);
};

#endif // GRAPHICSIMAGE_H
