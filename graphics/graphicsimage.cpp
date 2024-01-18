//2D图源显示控件(主要负责缩放)
#include "graphicsimage.h"
#include<QDebug>
//#pragma execution_character_set("utf-8")
GraphicsImage::GraphicsImage(QWidget *parent):
    mouse_click(false)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setMouseTracking(true);
}

void GraphicsImage::wheelEvent(QWheelEvent *event)
{
    m_lastPointF=event->pos();
    //还原图像缩放比
    scale(1/m_scale, 1/m_scale);
    translate(event->posF().x(),event->posF().y());
    if(event->angleDelta().y() > 0){
        if(m_scale < 10){
            m_scale += 0.2;
        }else{
            m_scale = 10;
        }
    }else{
        if(m_scale > 0.3){
            m_scale -= 0.2;
        }else{
            m_scale = 0.2;
        }
    }
    //修改图像缩放比
    scale(m_scale, m_scale);
    emit mousemove(m_scale,mapToScene(m_lastPointF));
}

//void GraphicsImage::mousePressEvent(QMouseEvent *event)
//{
//    emit mousemove(m_scale,mapToScene(event->pos()));
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
//}

//void GraphicsImage::mouseEnterEvent(QKeyEvent  *event)
//{
////    QPointF disPointF = event->pos() ;
////    emit mousemove(m_scale,mapToScene(event.));
//    qDebug()<<6;
//    if(event->button()== Qt::LeftButton)
//    {
//        QPointF point = (event->pos() - m_lastPointF) ;
//        translate(point.x(),point.y());
//    }
//    m_lastPointF = event->pos();
//}

//void GraphicsImage::mouseReleaseEvent(QMouseEvent *event)
//{
//    QCursor cursor;
//    setCursor(cursor);
//     mouse_click=false;//标记鼠标左键已经抬起
//}

//void GraphicsImage::translate(QPointF delta)
//{
//    delta *= m_scale;
//    // view 根据鼠标下的点作为锚点来定位 scene
//    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//    QPoint newCenter(this->width()/2-delta.x(),this->height()/2-delta.y());
//    centerOn(mapToScene(newCenter));
//    // scene 在 view 的中心点作为锚点
//    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
//}
