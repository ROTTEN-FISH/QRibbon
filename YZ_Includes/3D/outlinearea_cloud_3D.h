﻿/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	planeness_cloud_3D.h
Description: 提供点云截面积计算的算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-21 :  V1.0  :  SR  :  创建文件；
             2  :  2022-04-22 :  V1.0  :  SR  :  完善算法 修改bug；
			 3  :  2022-04-26 :  V1.0  :  SR  :  拿出轮廓点云作为一个算子，修复相关bug;
*************************************************/
#pragma once



#include "YZ_Includes/public/YZ_Vtypes.h"
//#include "YZ_Vexport.h"
#include "YZ_Includes/public/YZ_Vwarnings.h"
#include "YZ_Vbasic3D.h"
#include "YZ_Vtypedef3D.h"


#include <iostream>
#include <ctime>
#include<fstream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>


//pcl 库

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <pcl/filters/extract_indices.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/common/distances.h>
#include <Eigen/Core>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>  ///ransac 拟合平面
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/common/common_headers.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/filters/statistical_outlier_removal.h>//离群点去除
#include <pcl/common/common.h>


//opencv 库
#include<opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "opencv2/opencv_modules.hpp"
#include <opencv2/core/utility.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/stitching/detail/autocalib.hpp"
#include "opencv2/stitching/detail/blenders.hpp"
#include "opencv2/stitching/detail/timelapsers.hpp"
#include "opencv2/stitching/detail/camera.hpp"
#include "opencv2/stitching/detail/exposure_compensate.hpp"
#include "opencv2/stitching/detail/matchers.hpp"
#include "opencv2/stitching/detail/motion_estimators.hpp"
#include "opencv2/stitching/detail/seam_finders.hpp"
#include "opencv2/stitching/detail/warpers.hpp"
#include "opencv2/stitching/warpers.hpp"

using namespace cv;

using namespace cv::xfeatures2d;

using namespace std;

namespace YZVision
{
	class Outlinearea_3D :public Basic3D
	{
	public: Outlinearea_3D();
		  ~Outlinearea_3D();

		  using Basic3D::m_PointCloudROI;
		  /*
		   * 输入参数
		   * inputcloud 输入点云数据
		   * m_StartPoint roi左下坐标
		   * m_StartPoint roi右下坐标
		   * x_0 布尔值 是否选择roi模式获取面积，还是输入两点模式
		   * y_0 某个y方向的值
		   * XXX  0 为4点截面积算法，1 为计算所有点截面积算法
		   */

		  class InputParam
		  {
		  public:
			  YZVision::vPointsXYZ* inputcloud = NULL;
			  YZVision::PointXYZ m_StartPoint;
			  YZVision::PointXYZ m_EndPoint;
			  bool x_0 = 0;
			  //float y_0 = 0;
			  int XXX = 0;
		  };

		  /*
		   * 输出参数
		   * outputcloud_outline 输出的轮廓点云数据
		   * outputcloud_roi 输出的roi点云数据
		   * s_0 点云截面积
		   */
		  class OutputParam
		  {
		  public:
			  YZVision::vPointsXYZ outputcloud_outline;
			  YZVision::vPointsXYZ outputcloud_roi;
			  float s_0 = 0;
		  };
		  /*
			  * 函数描述: 实现点云截面积计算.
			  * 返 回 值: 参考YZ_Vwarnings.h

		  */
		  uint32_t outlinearea(InputParam inputParam, OutputParam* outputParam);

	private:
		uint32_t setInputCloud(vPointsXYZ* _cloud);
		//uint32_t outlinecloud(vPointsXYZ* inputcloud, float y_0, vPointsXYZ* outputcloud);
		uint32_t CutCloudroi(vPointsXYZ* inputcloud, PointXYZ m_StartPoint, PointXYZ m_EndPoint, vPointsXYZ* outputcloud);
		uint32_t OutlineRoiArea(vPointsXYZ* inputcloud, int XXX, float& s_0);
		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI);
		uint32_t qumianlinecloud(vPointsXYZ* inputcloud, PointsXYZ cloud_left, PointsXYZ cloud_right, int XXX, float& s_0);
	};

}
