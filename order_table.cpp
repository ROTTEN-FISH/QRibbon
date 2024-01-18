//算子操作的添加与初始值
#include "order_table.h"
#include<QDropEvent>
#include<QByteArray>
#include <QMimeData>
#include<QDataStream>
#include<QStandardItemModel>
order_table::order_table(QWidget *parent) : QTableWidget(parent)
{

//    this->setDragDropMode(QAbstractItemView::InternalMove);  // 内部移动
        this->setDropIndicatorShown(true);  // drop位置 提示
//    this->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void order_table::dragEnterEvent(QDragEnterEvent *event)
{
    event->setDropAction(Qt::CopyAction);
    event->accept();
}

void order_table::dropEvent(QDropEvent *event)
{
     QVariant var;
    if(event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
            QStandardItemModel dummy_model;
            if(dummy_model.dropMimeData(event->mimeData(), event->dropAction(), 0, 0, QModelIndex()))
            {
                QModelIndex index = dummy_model.index(0, 0);
                var=index.data();
            }

    }
    int row=this->rowAt(event->pos().y());

    QTableWidgetItem *current =this->item(row,1);
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText(var.toString());
    if(current !=nullptr){
        this->insertRow(this->rowCount());
        for(int i=this->rowCount();i>row;i--){
            for(int j=0;j<this->columnCount();j++)
                this->setItem(i,j,this->takeItem(i-1,j));
        }

    }else{
        if(row>=0){
            this->insertRow(this->rowCount());
        }else{
            row=this->rowCount();
            this->insertRow(this->rowCount());
        }

    }
    this->setItem(row,1,item->clone());
    this->setItem(row,3,item->clone());
    item->setText("0");
    this->setItem(row,2,item->clone());
    this->setItem(row,5,item->clone());
    this->setItem(row,6,item->clone());
    this->setItem(row,7,item->clone());
    item->setText("on");
    this->setItem(row,0,item->clone());
    if(var.toString()==QString::fromLocal8Bit("选择图像"))
        item->setText(QString::fromLocal8Bit(""));
    else if(var.toString()==QString::fromLocal8Bit("二值化图像"))
        item->setText(QString::fromLocal8Bit("raw_image=1,Adaptive=false,upper_threshold=127,lower_threshold=127,forecolor=255,backcolor=0"));
    else if(var.toString()==QString::fromLocal8Bit("膨胀/腐蚀"))
        item->setText(QString::fromLocal8Bit("raw_image=1,Iteration_time=1,Expansion=true"));
    else if(var.toString()==QString::fromLocal8Bit("图像运算"))
        item->setText(QString::fromLocal8Bit("raw_image_1=1,raw_image_2=1,add_1=0.5,operation=+,add_2=0.5"));
    else if(var.toString()==QString::fromLocal8Bit("斑点查找"))
        item->setText(QString::fromLocal8Bit("raw_image=1,type=0,threshold_lower=0,threshold_upper=50,border=false,fill=false,width_f=false,width_f_min=1,width_f_max=100,height_f=false,height_f_min=1,height_f_max=100,area=false,area_min=1,area_max=100,number=false,number_min=1,number_max=100"));
    else if(var.toString()==QString::fromLocal8Bit("线查找"))
        item->setText(QString::fromLocal8Bit("raw_image=1,threshold_lower=0,threshold_upper=50,type=0,border=0,ratio=100,Subpixel=0"));
    else if(var.toString()==QString::fromLocal8Bit("圆查找"))
        item->setText(QString::fromLocal8Bit("raw_image=1,threshold_lower=0,threshold_upper=50,type=0,border=0,ratio=100,radius_min=-5,radius_max=5"));
    else if(var.toString()==QString::fromLocal8Bit("模板匹配"))
        item->setText(QString::fromLocal8Bit("raw_image_1=1,raw_image_2=1,rotate=0,rotate_min=0,rotate_max=0,zoom=0,zoom_min=1,zoom_max=1,type=0,search=70,number=1"));
    else if(var.toString()==QString::fromLocal8Bit("测距"))
        item->setText(QString::fromLocal8Bit("raw_image=1,raw_image_2=1"));
    else if(var.toString()==QString::fromLocal8Bit("面积计算"))
        item->setText(QString::fromLocal8Bit("raw_image=1,blob=0"));
    else if(var.toString()==QString::fromLocal8Bit("图片拼接"))
        item->setText(QString::fromLocal8Bit("raw=1,raw_2=1,upper_threshold=255,lower_threshold=127,black=1,number=1"));
    else if(var.toString()==QString::fromLocal8Bit("选择点云"))
        item->setText(QString::fromLocal8Bit(""));
    else if(var.toString()==QString::fromLocal8Bit("找边缘点"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,direction=0"));
    else if(var.toString()==QString::fromLocal8Bit("找拐点"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,direction=0,threshold=0.1"));
    else if(var.toString()==QString::fromLocal8Bit("找线"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,direction=0,type=0"));
    else if(var.toString()==QString::fromLocal8Bit("找面"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,direction=0"));
    else if(var.toString()==QString::fromLocal8Bit("找质心"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1"));
    else if(var.toString()==QString::fromLocal8Bit("拼接"))
        item->setText(QString::fromLocal8Bit("raw_cloud_1=1,raw_cloud_2=1,CORP=0,move=0,low=0,high=50"));
    else if(var.toString()==QString::fromLocal8Bit("平滑"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,radius=0"));
    else if(var.toString()==QString::fromLocal8Bit("去重"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,direction=0,low=0,high=50,move=0"));
    else if(var.toString()==QString::fromLocal8Bit("3D转深度图"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,zoom=1,zoom_y=1,wave=0,threshold=0"));
    else if(var.toString()==QString::fromLocal8Bit("重采样"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,type=0,length=0,radius=0,step=0"));
    else if(var.toString()==QString::fromLocal8Bit("滤波"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,type=0,direction=0,up=0,down=0,number=0,zoom=1,save=0"));
    else if(var.toString()==QString::fromLocal8Bit("裁切"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,in=1"));
    else if(var.toString()==QString::fromLocal8Bit("拟合圆柱"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1"));
    else if(var.toString()==QString::fromLocal8Bit("曲面展开"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1"));
    else if(var.toString()==QString::fromLocal8Bit("点到点"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,raw_cloud2=1"));
    else if(var.toString()==QString::fromLocal8Bit("点到线"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,raw_cloud2=1"));
    else if(var.toString()==QString::fromLocal8Bit("点到面"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,raw_cloud2=1"));
    else if(var.toString()==QString::fromLocal8Bit("线到线"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,raw_cloud2=1"));
    else if(var.toString()==QString::fromLocal8Bit("线到面"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,raw_cloud2=1,direction=0"));
    else if(var.toString()==QString::fromLocal8Bit("面到面"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,raw_cloud2=1,direction=0"));
    else if(var.toString()==QString::fromLocal8Bit("平整度"))
        item->setText(QString::fromLocal8Bit("raw_cloud1=1,threshold=1"));
    else if(var.toString()==QString::fromLocal8Bit("截面积"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,four=0,custom=0,custom_min=1,custom_max=1"));
    else if(var.toString()==QString::fromLocal8Bit("锚定"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1"));
    else if(var.toString()==QString::fromLocal8Bit("矫正"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,line=0"));
    else if(var.toString()==QString::fromLocal8Bit("零平面"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,plane1=1,plane2=1"));
    else if(var.toString()==QString::fromLocal8Bit("轮廓点云"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,y=0"));
    else if(var.toString()==QString::fromLocal8Bit("3d斑点高度"))
        item->setText(QString::fromLocal8Bit("raw_cloud=1,radius=1,number=1"));
    this->setItem(row,4,item->clone());
    if(var.toString()==QString::fromLocal8Bit("圆查找"))
        item->setText(QString::fromLocal8Bit("圆形"));
    else if(var.toString()==QString::fromLocal8Bit("模板匹配"))
        item->setText(QString::fromLocal8Bit("矩形,矩形"));
    else
        item->setText(QString::fromLocal8Bit("矩形"));
    this->setItem(row,8,item->clone());

    if(var.toString()==QString::fromLocal8Bit("圆查找")){
        item->setText(QString::fromLocal8Bit("100,100,100,200,0"));
    }else if(var.toString()==QString::fromLocal8Bit("线查找"))
        item->setText(QString::fromLocal8Bit("1,1,100,100,0"));
    else if(var.toString()==QString::fromLocal8Bit("图像运算"))
        item->setText(QString::fromLocal8Bit("0,0,100,100,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("模板匹配"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("测距"))
        item->setText(QString::fromLocal8Bit("1,1,100,100"));
    else if(var.toString()==QString::fromLocal8Bit("找边缘点"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("找拐点"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("找线"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("找面"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("找质心"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("裁切"))
        item->setText(QString::fromLocal8Bit("0,0,0,20,20,20,0,0,0,20,20,20"));
    else if(var.toString()==QString::fromLocal8Bit("拟合圆柱"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("平整度"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("截面积"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("锚定"))
        item->setText(QString::fromLocal8Bit("0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("矫正"))
        item->setText(QString::fromLocal8Bit("0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("线到面"))
        item->setText(QString::fromLocal8Bit("0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("面到面"))
        item->setText(QString::fromLocal8Bit("0,0,0"));
    else if(var.toString()==QString::fromLocal8Bit("3d斑点高度"))
        item->setText(QString::fromLocal8Bit("0,0,0,0,0,0,0,0,0,0,0,0"));
    else
        item->setText(QString::fromLocal8Bit("0,0,0,0,0"));
    this->setItem(row,9,item->clone());
    if(var.toString()==QString::fromLocal8Bit("选择图像"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("二值化图像"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("膨胀/腐蚀"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("图像运算"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("斑点查找"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("线查找"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("圆查找"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("模板匹配"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("测距"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("面积计算"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("图片拼接"))
        item->setText(QString::fromLocal8Bit("2D"));
    else if(var.toString()==QString::fromLocal8Bit("3D转深度图"))
        item->setText(QString::fromLocal8Bit("2D"));
    else{
        item->setText("0,0");
        this->setItem(row,5,item->clone());
        this->setItem(row,6,item->clone());
        this->setItem(row,7,item->clone());
        item->setText(QString::fromLocal8Bit("3D"));
    }
    this->setItem(row,10,item->clone());
    emit changed();
}

