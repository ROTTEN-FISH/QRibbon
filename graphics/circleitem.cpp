//圆ROI
#include "circleitem.h"
#include <QtMath>
#include <QDebug>
CircleItem::CircleItem(QGraphicsItem *parent):
    size(0,0,200,200),
    in_size(50,50,100,100),
    FLAG("none"),
    f(false)
{
    //setSize(size);
    setCursor(Qt::ArrowCursor);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    temp=0;
}
QRectF CircleItem::boundingRect() const
{
    if(size.height()>in_size.height())
        return QRectF(size.x(),size.y(),size.width(),size.height());
    else
        return QRectF(in_size.x(),in_size.y(),in_size.width(),in_size.height());
}

void CircleItem::setSize(QRectF new_size,bool fixed){
    f=fixed;
    size.setX(size.center().x()-new_size.width()/2);
    size.setY(size.center().y()-new_size.width()/2);
    size.setWidth(new_size.width());
    size.setHeight(new_size.width());
    in_size.setX(size.center().x()-new_size.height()/2);
    in_size.setY(size.center().y()-new_size.height()/2);
    in_size.setWidth(new_size.height());
    in_size.setHeight(new_size.height());
}

void CircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen mPen = QPen(QColor(254,200,0));
    mPen.setWidth(2);
    painter->setPen(mPen);
    //抗锯齿
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::LosslessImageRendering );
    painter->drawEllipse(size);
    QPen mPen1 = QPen(QColor(50,180,50));
    mPen1.setWidth(2);
    painter->setPen(mPen1);
    painter->drawEllipse(in_size);
}

void CircleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->button()== Qt::LeftButton)
    {
        click_point=event->pos();
        qreal height,width,distance;
        height=size.y()+size.height()/2-click_point.y();
        width=size.x()+size.width()/2-click_point.x();
        distance=sqrt(width*width+height*height);
        if(distance>size.width()/2-3&&distance<size.width()/2+3){
            FLAG="stretch";
        }else if(distance>in_size.width()/2-33&&distance<in_size.width()/2+3){
            FLAG="instretch";
        }else if(distance<size.width()/2){
            FLAG="move";
        }else
            FLAG="none";
        if(f)
            FLAG="move";
        event->accept();
        mouseMoveEvent(event);
    }

//    mouseMoveEvent(event);
}

void CircleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = (event->pos() - click_point);
    qreal length;
    if(fabs(point.x())>fabs(point.y()))
        if(click_point.x()>boundingRect().center().x())

            length=point.x();
        else
            length=-point.x();
    else
        if(click_point.y()>boundingRect().center().y())
            length=point.y();
        else
            length=-point.y();

//    if(click_point.x()<scenePos().x()+boundingRect().width()/2||click_point.y()<scenePos().y()+boundingRect().width()/2)
//        length=-length;
    if(FLAG=="move"){
        //QPointF point = (event->pos() - click_point);
        moveBy(point.x(), point.y());

//        setSize(size);
        scene()->update();
    }else if(FLAG=="stretch"){
        qreal height;
        if(length!=0)
            height=fabs(size.height()+length-temp);
        else
            height=fabs(size.height());
        temp=length;
//        if(height<in_size.height()){
//            size=in_size;
//            in_size.setWidth(height);
//            in_size.setHeight(height);
//            in_size.setX(size.center().x()-in_size.width()/2);
//            in_size.setY(size.center().y()-in_size.height()/2);
//            FLAG=="instretch";
//        }else{
            size.setX(size.center().x()-height/2);
            size.setY(size.center().y()-height/2);
            size.setWidth(height);
            size.setHeight(height);
//        }
        scene()->update();
    }else if(FLAG=="instretch"){
        qreal height;
        if(length!=0)
            height=fabs(in_size.height()+length-temp);
        else
            height=fabs(in_size.height());
        temp=length;
//        if(height>size.height()){
//            in_size=size;
//            size.setWidth(height);
//            size.setHeight(height);
//            size.setX(size.center().x()-size.width()/2);
//            size.setY(size.center().y()-size.height()/2);
//            FLAG=="stretch";
//        }else{
            in_size.setX(in_size.center().x()-height/2);
            in_size.setY(in_size.center().y()-height/2);
            in_size.setWidth(height);
            in_size.setHeight(height);
//        }
        scene()->update();
    }
    QPointF o=(scenePos()+boundingRect().center());

    QPointF c=(scenePos()+boundingRect().topLeft());
    qreal width;
    if(size.width()>in_size.width())
        width=in_size.width();
    else
        width=size.width();
    QPointF in_c;
    in_c.setX(o.x()-width/2);
    in_c.setY(o.y()-width/2);
    emit mysignals(2,o,c,in_c,o,o,-1);
//    if(event->button()==Qt::LeftButton)
//        event->accept();
//    else
//        mouseReleaseEvent(event);
}

void CircleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
