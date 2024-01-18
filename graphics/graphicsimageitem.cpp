//2D图片显示(显示鼠标在图片中的坐标)
#include "graphicsimageitem.h"
#include<QDebug>
graphicsimageitem::graphicsimageitem(QPixmap pix)
{
    setPixmap(pix);
    setAcceptHoverEvents(true);
}

//void graphicsimageitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    //if(0)
////    if(event->button()== Qt::LeftButton)
////    {
////        QCursor cursor1;//创建光标对象
////        cursor1.setShape(Qt::OpenHandCursor);//设置光标形态为手掌
////        setCursor(cursor1);
////        m_lastPointF = event->pos();
////        mouse_click=true;
////        if(itemAt(event->pos())){

////        }
////    }
//    qDebug()<<"a";
//    mouseMoveEvent(event);
//}
void graphicsimageitem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
    emit mousemove(-1,event->pos());
}
//void graphicsimageitem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{

//    qDebug()<<1;
//    emit mousemove(-1,event->pos());
//}
