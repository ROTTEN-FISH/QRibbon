//#pragma once
#include<QMainWindow>
#include<QTableWidgetItem>
#include<QGraphicsScene>
#include<QDebug>
#include<QTreeWidgetItem>
#include<QTime>
#include "VTKHeaders.h"
#include <QVTKWidget.h>

#include <boost/thread/thread.hpp>
#include "mouseinteractorstyle5.h"
#include "custommouseinteractorstyle.h"

#include <pcl/io/pcd_io.h>
#include <QLabel>
//YZ公共类
#include "YZ_Includes/public/YZ_Vtypes.h"
#include "YZ_Includes/public/YZ_Vwarnings.h"

//2d公共类
#include "YZ_Includes/2D/aiv.h"
#include "YZ_Includes/2D/YZ_Vbasic2D.h"
#include "YZ_Includes/2D/YZ_Vtypedef2D.h"
#include "YZ_Includes/2D/KcgMatch.h"

//二值化
#include "YZ_Includes/2D/binary_2D.h"
//膨胀腐蚀
#include "YZ_Includes/2D/morphology_2D.h"
//图像运算
#include "YZ_Includes/2D/math_2D.h"
//找斑点
#include "YZ_Includes/2D/find_blob_2D.h"
//找线
#include "YZ_Includes/2D/find_line_2D.h"
//找圆
#include "YZ_Includes/2D/find_circle_2D.h"
//模板匹配
#include "YZ_Includes/2D/match_template_2D.h"
//计算面积
#include "YZ_Includes/2D/calc_area_2D.h"
//测距
#include "YZ_Includes/2D/calc_distance_2D.h"
//图像拼接
#include "YZ_Includes/2D/imagesplicing_2D.h"

//3d公共类
#include "YZ_Includes/3D/YZ_Vtypedef3D.h"
#include "YZ_Includes/3D/YZ_Vbasic3D.h"
#include "YZ_Includes/3D/feature.h"
#include "YZ_Includes/3D/segmentation.h"
#include "YZ_Includes/3D/measurement.h"
#include "YZ_Includes/3D/transformation.h"

//读取点云
#include "YZ_Includes/3D/read_cloud_3D.h"

//3Dblob
//找边缘点
#include "YZ_Includes/3D/find_edgepoints_3D.h"
//找拐点
#include "YZ_Includes/3D/find_turningpoints_3D.h"
//找线
#include "YZ_Includes/3D/find_line_3D.h"
//找面
#include "YZ_Includes/3D/find_plane_3D.h"
//找质心
#include "YZ_Includes/3D/find_centroid_3D.h"

//3D预处理
//点云拼接
#include "YZ_Includes/3D/cloud_splicing_3D.h"
//平滑
#include "YZ_Includes/3D/fullup_cloud_3D.h"
//去重
#include "YZ_Includes/3D/cloud_deduplication_3D.h"
//3d转深度图
#include "YZ_Includes/3D/deep_cloud_3D.h"
//重采样
#include "YZ_Includes/3D/up_resampling_3D.h"
#include "YZ_Includes/3D/down_resampling_3D.h"
#include "YZ_Includes/3D/average_resampling_3D.h"
//滤波
#include "YZ_Includes/3D/passthrough_filter_3D.h"
#include "YZ_Includes/3D/statistical_cloud_3D.h"
#include "YZ_Includes/3D/radius_cloud_3D.h"
//裁切
#include "YZ_Includes/3D/cut_cloud_3D.h"
//拟合圆柱
#include "YZ_Includes/3D/find_cylinder_3D.h"
//曲面展开

//锚定
#include "YZ_Includes/3D/move_point_cloud.h"
//矫正
#include "YZ_Includes/3D/rotate_point_cloud.h"
//零平面
#include "YZ_Includes/3D/cloud_zeroplane_3D.h"
//轮廓点云
#include "YZ_Includes/3D/cloud_outline_3D.h"
//3D计算
//点到点
#include "YZ_Includes/3D/point_point_distance.h"
//点到线
#include "YZ_Includes/3D/point_line_distance.h"
//点到面
#include "YZ_Includes/3D/point_plane_distance.h"
//线到线
#include "YZ_Includes/3D/line_line_distance.h"
//线到面
#include "YZ_Includes/3D/line_plane_distance.h"
//面到面
#include "YZ_Includes/3D/plane_plane_distance.h"
//平整度
#include "YZ_Includes/3D/planeness_cloud_3D.h"
//截面积
#include "YZ_Includes/3D/outlinearea_cloud_3D.h"
//3d斑点高度
#include "YZ_Includes/3D/cloud_seg_3D.h"
namespace Ui { class VGRibbonWindow; };

class VGRibbonWindow : public QMainWindow
{
    Q_OBJECT
public:
    VGRibbonWindow(QWidget *parent = Q_NULLPTR);
    ~VGRibbonWindow();
    static int c_row,c_column,roi;
    static double x_max,x_min,y_max,y_min,z_max,z_min,sc;
    static bool isshow,Copied,click,fixed,changed,_3D,pattern_changed;
private slots:
    void time_update();
    //设置输入格式
    void Input_format();
    //命令集点击事件
    void on_command_set_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    //指令栏点击事件
    void on_ordertable_cellClicked(int row, int column);
    //显示坐标
    void showinfo(qreal scale, QPointF p);
    //显示3D坐标
    void show3Dinfo(double x, double y,double z);
    //右键菜单
    void show_menu(const QPoint pos);
    //复制
    void copy();
    //剪切
    void cut();
    //黏贴
    void paste();
    //移除
    void remove();

    //新建文件
    void newfile();
    //保存文件
    void savefile();
    //打开文件
    void openfile();
    //设置更改后操作
    void settingchanged();
    //退出
    void quit();

    //添加工具原点
    void origin_add(int n,int x,int y);
    //更新原点坐标
    void updateOriginPos(QPointF pos,int n);

    //添加ROI事件
    void ROI_add(int type,qreal x,qreal y,qreal width,qreal height,qreal a);
    //更新ROI坐标
    void updateItemPos(int type,QPointF pos,QPointF lt,QPointF rt,QPointF rb,QPointF lb,int Rotate );

    //添加3DROI
    void ROI_add_3D(qreal p_x,qreal p_y,qreal p_z,qreal length,qreal width,qreal height);
    //更新3DROI坐标
    void update3DItemPos(double x,double y,double z,double Scalex,double Scaley,double Scalez);

    //添加3D锚点
    void origin_add_3D(qreal p_x,qreal p_y,qreal p_z);

    //计算边界坐标
    void boundary_position(int type,qreal x,qreal y,qreal width,qreal height,qreal a);

    //视角切换
    void on_view_reset_clicked();

    void on_view_up_clicked();

    void on_view_front_clicked();

    void on_view_left_clicked();

    void on_view_back_clicked();

    void on_view_right_clicked();

    void on_view_bottom_clicked();

    void on_view_frontlso_clicked();

    void on_view_backlso_clicked();

    //运行
    void on_pushButton_clicked();
    //单步运行
    void on_singerun_clicked();

    //输出列表点击事件
    void on_out_list_itemClicked(QTreeWidgetItem *item, int column);
    //输出列表详情展开
    void on_expansion_clicked();
    //图片选择事件
    void on_choose_image_clicked();

    void on_choose_image_width_editingFinished();

    void on_choose_image_height_editingFinished();

    void on_image_rotate_editingFinished();

    void on_origin_x_editingFinished();

    void on_origin_y_editingFinished();

    //binary_image中General点击事件
    void on_binary_image_General_clicked();
    //binary_image中ROI点击事件
    void on_binary_image_ROI_clicked();

    void on_binary_image_ROI_cancel_clicked();
    //binary_image中preview点击事件
    void on_binary_image_preview_clicked();    
    //binary_image设置保存事件
    void binary_image_setting_changed();

    void on_binary_image_adaptive_stateChanged(int arg1);

    void on_binary_image_raw_image_currentIndexChanged(int index);
    //binary_image上阈限更改事件
    void on_binary_image_upper_threshold_editingFinished();
    //binary_image降低门槛更改事件
    void on_binary_image_lower_threshold_editingFinished();
    //binary_image前景色更改事件
    void on_binary_image_forecolor_editingFinished();
    //binary_image背景色更改事件
    void on_binary_image_backcolor_editingFinished();
    //binary_image的ROI中x坐标更改事件
    void on_binary_image_x_textChanged(const QString &arg1);
    //binary_image的ROI中y坐标更改事件
    void on_binary_image_y_textChanged(const QString &arg1);
    //binary_image的ROI中高度更改事件
    void on_binary_image_height_textChanged(const QString &arg1);
    //binary_image的ROI中宽度更改事件
    void on_binary_image_width_textChanged(const QString &arg1);

    void on_binary_image_a_textChanged(const QString &arg1);

    void on_binary_image_a_editingFinished();

    void on_binary_image_x_editingFinished();

    void on_binary_image_y_editingFinished();

    void on_binary_image_height_editingFinished();

    void on_binary_image_width_editingFinished();

    void on_binary_image_type_currentIndexChanged(int index);

    void binary_image_ROI_check();

    //膨胀腐蚀
    void on_Expansion_corrosion_General_clicked();

    void on_Expansion_corrosion_ROI_clicked();

    void on_Expansion_corrosion_ROI_cancel_clicked();

    void on_Expansion_corrosion_preview_clicked();

    void Expansion_corrosion_setting_changed();

    void on_Expansion_corrosion_Iteration_time_editingFinished();

    void on_Expansion_corrosion_raw_image_currentIndexChanged(int index);

    void on_Expansion_corrosion_x_textChanged(const QString &arg1);

    void on_Expansion_corrosion_y_textChanged(const QString &arg1);

    void on_Expansion_corrosion_height_textChanged(const QString &arg1);

    void on_Expansion_corrosion_width_textChanged(const QString &arg1);

    void on_Expansion_corrosion_a_textChanged(const QString &arg1);

    void on_Expansion_corrosion_a_editingFinished();

    void on_Expansion_corrosion_x_editingFinished();

    void on_Expansion_corrosion_y_editingFinished();

    void on_Expansion_corrosion_height_editingFinished();

    void on_Expansion_corrosion_width_editingFinished();

    void on_Expansion_corrosion_type_currentIndexChanged(int index);

    void Expansion_corrosion_ROI_check();

    //图像运算
    void on_image_math_general_clicked();

    void on_image_math_ROI_clicked();

    void on_image_math_ROI_cancel_clicked();

    void on_image_math_preview_clicked();

    void image_math_setting_changed();

    void on_image_math_raw_image_1_currentIndexChanged(int index);

    void on_image_math_raw_image_2_currentIndexChanged(int index);

    void on_image_math_operation_currentTextChanged(const QString &arg1);

    void on_image_math_add_1_editingFinished();

    void on_image_math_add_2_editingFinished();

    void on_image_math_x_textChanged(const QString &arg1);

    void on_image_math_y_textChanged(const QString &arg1);

    void on_image_math_height_textChanged(const QString &arg1);

    void on_image_math_width_textChanged(const QString &arg1);

    void on_image_math_a_textChanged(const QString &arg1);

    void on_image_math_a_editingFinished();

    void on_image_math_x_editingFinished();

    void on_image_math_y_editingFinished();

    void on_image_math_height_editingFinished();

    void on_image_math_width_editingFinished();

    void on_image_math_type_currentIndexChanged(int index);

    void image_math_ROI_1_check();

    void on_image_math_2_x_textChanged(const QString &arg1);

    void on_image_math_2_y_textChanged(const QString &arg1);

    void on_image_math_2_x_editingFinished();

    void on_image_math_2_y_editingFinished();

    void on_image_math_ROI_2_clicked();

    void image_math_ROI_2_check();

    //斑点查找
    void on_blob_general_clicked();

    void on_blob_ROI_clicked();

    void on_blob_preview_clicked();

    void blob_setting_changed();

    void on_blob_raw_image_currentIndexChanged(int index);

    void on_blob_type_currentIndexChanged(int index);

    void on_blob_threshold_lower_editingFinished();

    void on_blob_threshold_upper_editingFinished();

    void on_blob_exclude_borders_stateChanged(int arg1);

    void on_blob_fill_stateChanged(int arg1);

    void on_blob_ROI_x_textChanged(const QString &arg1);

    void on_blob_ROI_y_textChanged(const QString &arg1);

    void on_blob_ROI_height_textChanged(const QString &arg1);

    void on_blob_ROI_width_textChanged(const QString &arg1);

    void on_blob_ROI_a_textChanged(const QString &arg1);

    void on_blob_ROI_a_editingFinished();

    void on_blob_ROI_x_editingFinished();

    void on_blob_ROI_y_editingFinished();

    void on_blob_ROI_height_editingFinished();

    void on_blob_ROI_width_editingFinished();

    void on_blob_ROI_cancel_clicked();

    void on_blob_ROI_type_currentIndexChanged(int index);

    void blob_ROI_check();

    void on_blob_width_stateChanged(int arg1);

    void on_blob_width_min_editingFinished();

    void on_blob_width_max_editingFinished();

    void on_blob_height_stateChanged(int arg1);

    void on_blob_height_min_editingFinished();

    void on_blob_height_max_editingFinished();

    void on_blob_area_stateChanged(int arg1);

    void on_blob_area_min_editingFinished();

    void on_blob_area_max_editingFinished();

    void on_blob_number_stateChanged(int arg1);

    void on_blob_number_min_editingFinished();

    void on_blob_number_max_editingFinished();    

    //线查找
    void on_line_find_general_clicked();

    void on_line_find_ROI_clicked();

    void on_line_find_preview_clicked();

    void line_find_setting_changed();

    void on_line_find_raw_image_currentIndexChanged(int index);

    void on_line_find_threshold_lower_editingFinished();

    void on_line_find_threshold_upper_editingFinished();

    void on_line_find_type_currentIndexChanged(int index);

    void on_line_find_border_currentIndexChanged(int index);

    void on_line_find_ratio_editingFinished();

    void on_line_find_Subpixel_editingFinished();

    void on_line_find_x_textChanged(const QString &arg1);

    void on_line_find_y_textChanged(const QString &arg1);

    void on_line_find_height_textChanged(const QString &arg1);

    void on_line_find_width_textChanged(const QString &arg1);

    void on_line_find_a_textChanged(const QString &arg1);

    void on_line_find_a_editingFinished();

    void on_line_find_x_editingFinished();

    void on_line_find_y_editingFinished();

    void on_line_find_height_editingFinished();

    void on_line_find_width_editingFinished();

    void line_find_ROI_check();

    //圆查找
    void on_Circle_find_general_clicked();

    void on_Circle_find_ROI_clicked();

    void on_Circle_find_preview_clicked();

    void Circle_find_setting_changed();

    void on_Circle_find_raw_image_currentIndexChanged(int index);

    void on_Circle_find_threshold_lower_editingFinished();

    void on_Circle_find_threshold_upper_editingFinished();

    void on_Circle_find_type_currentIndexChanged(int index);

    void on_Circle_find_border_currentIndexChanged(int index);

    void on_Circle_find_ratio_editingFinished();

    void on_Circle_find_x_textChanged(const QString &arg1);

    void on_Circle_find_y_textChanged(const QString &arg1);

    void on_Circle_find_height_textChanged(const QString &arg1);

    void on_Circle_find_width_textChanged(const QString &arg1);

    void on_Circle_find_x_editingFinished();

    void on_Circle_find_y_editingFinished();

    void on_Circle_find_height_editingFinished();

    void on_Circle_find_width_editingFinished();

    void Circle_find_ROI_check();

    void on_Circle_find_radius_min_returnPressed();

    void on_Circle_find_radius_max_returnPressed();

    //模板匹配
    void on_Pattern_find_general_clicked();

    void on_Pattern_find_train_ROI_clicked();

    void on_Pattern_find_search_ROI_clicked();

    void on_Pattern_find_preview_clicked();

    void Pattern_find_setting_change();

    void on_Pattern_find_train_raw_image_currentIndexChanged(int index);

    void on_Pattern_find_search_raw_image_currentIndexChanged(int index);

    void on_Pattern_find_rotate_currentIndexChanged(int index);

    void on_Pattern_find_rotate_min_editingFinished();

    void on_Pattern_find_rotate_max_editingFinished();

    void on_Pattern_find_zoom_currentIndexChanged(int index);

    void on_Pattern_find_zoom_min_editingFinished();

    void on_Pattern_find_zoom_max_editingFinished();

    void on_Pattern_find_type_currentIndexChanged(int index);

    void on_Pattern_find_ROI_x_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_y_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_height_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_width_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_a_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_a_editingFinished();

    void on_Pattern_find_ROI_x_editingFinished();

    void on_Pattern_find_ROI_y_editingFinished();

    void on_Pattern_find_ROI_height_editingFinished();

    void on_Pattern_find_ROI_width_editingFinished();

    void on_Pattern_find_ROI_type_currentIndexChanged(int index);

    void on_Pattern_find_ROI_cancel_clicked();

    void Pattern_find_ROI_check();

    void on_Pattern_find_ROI_2_x_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_2_y_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_2_height_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_2_width_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_2_a_textChanged(const QString &arg1);

    void on_Pattern_find_ROI_2_a_editingFinished();

    void on_Pattern_find_ROI_2_x_editingFinished();

    void on_Pattern_find_ROI_2_y_editingFinished();

    void on_Pattern_find_ROI_2_height_editingFinished();

    void on_Pattern_find_ROI_2_width_editingFinished();

    void on_Pattern_find_ROI_2_cancel_clicked();

    void Pattern_find_ROI_2_check();

    void on_Pattern_find_min_search_editingFinished();

    void on_Pattern_find_max_number_editingFinished();

    void on_Pattern_find_all_number_stateChanged(int arg1);

    void on_Pattern_find_ROI_2_type_currentIndexChanged(int index);

    //测距
    void on_length_General_clicked();

    void on_length_preview_clicked();

    void length_setting_change();

    void on_length_raw_image_currentIndexChanged(int index);

    void on_length_raw_image_2_currentIndexChanged(int index);

    void length_redraw();

    //面积计算
    void on_area_General_clicked();

    void on_area_preview_clicked();

    void area_setting_change();

    void on_area_raw_image_currentIndexChanged(int index);

    void on_area_blob_currentIndexChanged(int index);

    //图片拼接
    void on_image_Splicing_general_clicked();

    void on_image_Splicing_preview_clicked();

    void image_Splicing_setting_change();

    void on_image_Splicing_raw_2_currentIndexChanged(int index);

    void on_image_Splicing_raw_currentIndexChanged(int index);

    void on_image_Splicing_upper_threshold_editingFinished();

    void on_image_Splicing_lower_threshold_editingFinished();

    void on_image_Splicing_number_editingFinished();

    void on_image_Splicing_black_stateChanged(int arg1);

    //选择点云
    void on_cloud_choose_clicked();
    //点云显示
    void opencloud();

     void openrawcloud(YZVision::vPointsXYZ pts);

    void highLight(YZVision::vPointsXYZ pts);

    void highLightblob(YZVision::vPointsXYZ pts);

    void highLightline(int raw_cloud);

    void highLightplane(int raw_cloud);

    void highLighthistory(YZVision::vPointsXYZ pts);

    void highLightlinehistory(int raw_cloud);

    void highLightplanehistory(int raw_cloud);

    void setVtkLine(YZVision::PointXYZ a,YZVision::PointXYZ b);
    //找边缘点
    void on_point_general_clicked();

    void on_point_ROI_clicked();

    void on_point_preview_clicked();

    void point_setting_change();

    void point_ROI_change();

    void on_point_direction_currentIndexChanged(int index);

    void on_point_cloud_currentIndexChanged(int index);

    void on_point_x_editingFinished();

    void on_point_y_editingFinished();

    void on_point_z_editingFinished();

    void on_point_l_editingFinished();

    void on_point_w_editingFinished();

    void on_point_h_editingFinished();

    //找拐点
    void on_turning_general_clicked();

    void on_turning_ROI_clicked();

    void on_turning_preview_clicked();

    void turning_setting_change();

    void turning_ROI_change();

    void on_turning_cloud_currentIndexChanged(int index);

    void on_turning_direction_currentIndexChanged(int index);

    void on_turning_threshold_editingFinished();

    void on_turning_x_editingFinished();

    void on_turning_y_editingFinished();

    void on_turning_z_editingFinished();

    void on_turning_l_editingFinished();

    void on_turning_w_editingFinished();

    void on_turning_h_editingFinished();

    //找线
    void on_line_general_clicked();

    void on_line_ROI_clicked();

    void on_line_preview_clicked();

    void line_setting_change();

    void line_ROI_change();

    void on_line_cloud_currentIndexChanged(int index);

    void on_line_direction_currentIndexChanged(int index);

    void on_line_type_currentIndexChanged(int index);

    void on_line_x_editingFinished();

    void on_line_y_editingFinished();

    void on_line_z_editingFinished();

    void on_line_l_editingFinished();

    void on_line_w_editingFinished();

    void on_line_h_editingFinished();

    //找面
    void on_plane_general_clicked();

    void on_plane_ROI_clicked();

    void on_plane_preview_clicked();

    void plane_setting_change();

    void plane_ROI_change();

    void on_plane_cloud_currentIndexChanged(int index);

    void on_plane_direction_currentIndexChanged(int index);

    void on_plane_x_editingFinished();

    void on_plane_y_editingFinished();

    void on_plane_z_editingFinished();

    void on_plane_l_editingFinished();

    void on_plane_w_editingFinished();

    void on_plane_h_editingFinished();

    //找质心
    void on_Centroid_general_clicked();

    void on_Centroid_ROI_clicked();

    void on_Centroid_preview_clicked();

    void Centroid_setting_change();

    void Centroid_ROI_change();

    void on_Centroid_cloud_currentIndexChanged(int index);

    void on_Centroid_x_editingFinished();

    void on_Centroid_y_editingFinished();

    void on_Centroid_z_editingFinished();

    void on_Centroid_l_editingFinished();

    void on_Centroid_w_editingFinished();

    void on_Centroid_h_editingFinished();

    //拼接
    void on_Splicing_general_clicked();

    void on_Splicing_preview_clicked();

    void Splicing_setting_change();

    void on_Splicing_raw_cloud_1_currentIndexChanged(int index);

    void on_Splicing_raw_cloud_2_currentIndexChanged(int index);

    void on_Splicing_CROP_stateChanged(int arg1);

    void on_Splicing_CROP_low_editingFinished();

    void on_Splicing_CROP_high_editingFinished();

    void on_Splicing_CROP_move_editingFinished();

    //平滑
    void on_smooth_general_clicked();

    void on_smooth_preview_clicked();

    void smooth_setting_change();

    void on_smooth_raw_cloud_currentIndexChanged(int index);

    void on_smooth_radius_editingFinished();  

    //去重
    void on_CROP_general_clicked();

    void on_CROP_preview_clicked();

    void CROP_setting_change();

    void on_CROP_raw_cloud_currentIndexChanged(int index);

    void on_CROP_direction_currentIndexChanged(int index);

    void on_CROP_low_editingFinished();

    void on_CROP_high_editingFinished();

    void on_CROP_move_editingFinished();

    //3d转深度图
    void on_Deep_general_clicked();

    void on_Deep_preview_clicked();

    void Deep_setting_change();

    void on_Deep_raw_cloud_currentIndexChanged(int index);

    void on_Deep_zoom_editingFinished();

    void on_Deep_zoom_y_editingFinished();

    void on_Deep_wave_stateChanged(int arg1);

    void on_Deep_threshold_editingFinished();

    //重采样
    void on_sampling_general_clicked();

    void on_sampling_preview_clicked();

    void sampling_setting_change();

    void on_sampling_raw_cloud_currentIndexChanged(int index);

    void on_sampling_type_currentIndexChanged(int index);

    void on_sampling_length_editingFinished();

    void on_sampling_radius_editingFinished();

    void on_sampling_step_editingFinished();

    //滤波
    void on_wave_general_clicked();

    void on_wave_preview_clicked();

    void wave_setting_change();

    void on_wave_raw_cloud_currentIndexChanged(int index);

    void on_wave_type_currentIndexChanged(int index);

    void on_wave_direction_currentIndexChanged(int index);

    void on_wave_up_editingFinished();

    void on_wave_down_editingFinished();

    void on_wave_number_editingFinished();

    void on_wave_zoom_editingFinished();

    void on_wave_save_stateChanged(int arg1);

    //切割
    void on_getcloud_general_clicked();

    void on_getcloud_ROI_clicked();

    void on_getcloud_preview_clicked();

    void getcloud_setting_change();

    void getcloud_ROI_change();

    void on_getcloud_cloud_currentIndexChanged(int index);

    void on_getcloud_in_stateChanged(int arg1);

    void on_getcloud_x_editingFinished();

    void on_getcloud_y_editingFinished();

    void on_getcloud_z_editingFinished();

    void on_getcloud_l_editingFinished();

    void on_getcloud_w_editingFinished();

    void on_getcloud_h_editingFinished();

    //拟合圆柱
    void on_cylinderSegment_general_clicked();

    void on_cylinderSegment_ROI_clicked();

    void on_cylinderSegment_preview_clicked();

    void cylinderSegment_setting_change();

    void cylinderSegment_ROI_change();

    void on_cylinderSegment_cloud_currentIndexChanged(int index);

    void on_cylinderSegment_x_editingFinished();

    void on_cylinderSegment_y_editingFinished();

    void on_cylinderSegment_z_editingFinished();

    void on_cylinderSegment_l_editingFinished();

    void on_cylinderSegment_w_editingFinished();

    void on_cylinderSegment_h_editingFinished();

    //曲面展开
    void on_cylinderToPlane_general_clicked();

    void on_cylinderToPlane_preview_clicked();

    void cylinderToPlane_setting_change();

    void on_cylinderToPlane_cloud_currentIndexChanged(int index);

    //锚定
    void on_Anchor_general_clicked();

    void on_Anchor_preview_clicked();

    void Anchor_setting_change();

    void on_Anchor_cloud_currentIndexChanged(int index);

    void on_Anchor_x_editingFinished();

    void on_Anchor_y_editingFinished();

    void on_Anchor_z_editingFinished();

    //矫正
    void on_correct_general_clicked();

    void on_correct_preview_clicked();

    void correct_setting_change();

    void on_correct_cloud_currentIndexChanged(int index);

    void on_correct_line_stateChanged(int arg1);

    void on_correct_x_editingFinished();

    void on_correct_y_editingFinished();

    void on_correct_z_editingFinished();

    //零平面
    void on_zeroplane_general_clicked();

    void on_zeroplane_preview_clicked();

    void zeroplane_settingchange();

    void on_zeroplane_cloud_currentIndexChanged(int index);

    void on_zeroplane_cloud_plane_1_currentIndexChanged(int index);

    void on_zeroplane_cloud_plane_2_currentIndexChanged(int index);

    //点到点
    void on_point_point_general_clicked();

    void on_point_point_preview_clicked();

    void point_point_setting_change();

    void on_point_point_cloud_currentIndexChanged(int index);

    void on_point_point_cloud_2_currentIndexChanged(int index);

    //点到线
    void on_point_line_general_clicked();

    void on_point_line_preview_clicked();

    void point_line_setting_change();

    void on_point_line_cloud_currentIndexChanged(int index);

    void on_point_line_cloud_2_currentIndexChanged(int index);

    //点到面
    void on_point_plane_general_clicked();

    void on_point_plane_preview_clicked();

    void point_plane_setting_change();

    void on_point_plane_cloud_currentIndexChanged(int index);

    void on_point_plane_cloud_2_currentIndexChanged(int index);

    //线到线
    void on_line_line_general_clicked();

    void on_line_line_preview_clicked();

    void line_line_setting_change();

    void on_line_line_cloud_currentIndexChanged(int index);

    void on_line_line_cloud_2_currentIndexChanged(int index);

    //线到面
    void on_line_plane_general_clicked();

    void on_line_plane_preview_clicked();

    void line_plane_setting_change();

    void on_line_plane_cloud_2_currentIndexChanged(int index);

    void on_line_plane_cloud_currentIndexChanged(int index);

    void on_line_plane_direction_currentIndexChanged(int index);

    void on_line_plane_x_editingFinished();

    void on_line_plane_y_editingFinished();

    void on_line_plane_z_editingFinished();

    //面到面
    void on_plane_plane_general_clicked();

    void on_plane_plane_preview_clicked();

    void plane_plane_setting_change();

    void on_plane_plane_cloud_currentIndexChanged(int index);

    void on_plane_plane_cloud_2_currentIndexChanged(int index);

    void on_plane_plane_direction_currentIndexChanged(int index);

    void on_plane_plane_x_editingFinished();

    void on_plane_plane_y_editingFinished();

    void on_plane_plane_z_editingFinished();

    //平整度
    void on_planeness_general_clicked();

    void on_planeness_ROI_clicked();

    void on_planeness_preview_clicked();

    void planeness_setting_change();

    void planeness_ROI_change();

    void on_planeness_cloud_currentIndexChanged(int index);

    void on_planeness_threshold_editingFinished();

    void on_planeness_x_editingFinished();

    void on_planeness_y_editingFinished();

    void on_planeness_z_editingFinished();

    void on_planeness_l_editingFinished();

    void on_planeness_w_editingFinished();

    void on_planeness_h_editingFinished();

    //截面积
    void on_outline_general_clicked();

    void on_outline_ROI_clicked();

    void on_outline_preview_clicked();

    void outline_setting_change();

    void outline_ROI_change();

    void on_outline_cloud_currentIndexChanged(int index);

    void on_outline_four_stateChanged(int arg1);

    void on_outline_custom_stateChanged(int arg1);

    void on_outline_custom_min_currentIndexChanged(int index);

    void on_outline_custom_max_currentIndexChanged(int index);

    void on_outline_x_editingFinished();

    void on_outline_y_editingFinished();

    void on_outline_z_editingFinished();

    void on_outline_l_editingFinished();

    void on_outline_w_editingFinished();

    void on_outline_h_editingFinished();

    //3D斑点高度
    void on_Blob_3d_general_clicked();

    void on_Blob_3d_ROI_clicked();

    void on_Blob_3d_preview_clicked();

    void Blob_3d_setting_change();

    void Blob_3d_ROI_change();

    void on_Blob_3d_cloud_currentIndexChanged(int index);

    void on_Blob_3d_radius_editingFinished();

    void on_Blob_3d_number_editingFinished();

    void on_Blob_3d_x_editingFinished();

    void on_Blob_3d_y_editingFinished();

    void on_Blob_3d_z_editingFinished();

    void on_Blob_3d_l_editingFinished();

    void on_Blob_3d_w_editingFinished();

    void on_Blob_3d_h_editingFinished();

    //轮廓点云
    void on_Cloudoutline_general_clicked();

    void on_Cloudoutline_preview_clicked();

    void Cloudoutline_setting_change();

    void on_Cloudoutline_cloud_currentIndexChanged(int index);

    void on_Cloudoutline_y_editingFinished();


private:
    Ui::VGRibbonWindow *ui;
    //图像
    QPixmap image[1000],c_image,n_image,empty_image;
    //复制时的寄存器
    QString order_table_c_0,order_table_c_1,order_table_c_2,order_table_c_3,order_table_c_4,order_table_c_5;
    QString order_table_c_6,order_table_c_7,order_table_c_8,order_table_c_9,order_table_c_10;
    //打开文件地址
    QString openfilepath,openimagepath,opencloudpath;
    //2d roi边界
    YZVision::Basic2D::PointXY boundary[4];
    std::vector<YZVision::vPointsXYZ> cloudarrary;
    std::vector<std::vector<std::vector <float>>> res;
    //3d roi边界
    YZVision::PointXYZ start;
    YZVision::PointXYZ end;
    // VTK Renderer
    QVTKWidget* qvtkWidget;
    vtkSmartPointer<vtkPoints> points;
    vtkSmartPointer<vtkCellArray> vertices;
    vtkSmartPointer<vtkPolyData> polyData;
    //3d 过滤器
    vtkSmartPointer<vtkElevationFilter> elevationFilter;
    vtkSmartPointer<vtkPolyDataMapper> pointMapper;
    vtkSmartPointer<vtkActor> pointActor;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
    //3d 坐标轴
    vtkSmartPointer<vtkAxesActor> axesActor;
    vtkSmartPointer<vtkOrientationMarkerWidget> widgetAxes;
    //3d roi控件
    customMouseInteractorStyle* mouseStyle;
    //时间,用户
    QLabel *currentTimeLabel;
    QLabel *currentUserLabel;
    //颜色
    float color_r,color_g,color_b;
};
