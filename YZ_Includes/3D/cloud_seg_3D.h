/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	planeness_cloud_3D.h
Description: 提供点云斑点查找测高的算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-25 :  V1.0  :  SR  :  创建文件；

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

#include <pcl/segmentation/region_growing.h>//区域生长
#include <pcl/segmentation/extract_clusters.h>

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

using namespace cv::xfeatures2d;

using namespace std;

namespace YZVision
{
	class Cloudseg_3D :public Basic3D
	{
	public: Cloudseg_3D();
		  ~Cloudseg_3D();

		  using Basic3D::m_PointCloudROI;
		  /*
		   * 输入参数
		   * inputcloud 输入点云数据
		   * m_StartPoint roi左下坐标
		   * m_StartPoint roi右下坐标
		   * r_0 近邻搜索的半径
		   * num 所需聚类最少点数
		   */

		  class InputParam
		  {
		  public:
			  YZVision::vPointsXYZ* inputcloud = NULL;
			  YZVision::PointXYZ m_StartPoint;
			  YZVision::PointXYZ m_EndPoint;
			  float r_0 = 1;
			  int num = 0;
		  };
			  /*
			   * 输出参数
			   * outputcloud_pin 输出的pin针blob点云数据
			   * out_seg 存放分割后的点云数据，以二维数组存放
			   * num_0 存放pin针高度的一维数组
			   */
			  class OutputParam
			  {
			  public:
				  vPointsXYZ outputcloud_pin;
				  std::vector<YZVision::vPointsXYZ> out_seg;
				  //float* num_0;
				  float* num_0 = (float*)malloc(20 * sizeof(float));


			  };
			  /*
				  * 函数描述: 实现点云斑点查找测高.
				  * 返 回 值: 参考YZ_Vwarnings.h

			  */
			  uint32_t cloudseg(InputParam inputParam, OutputParam* outputParam);
		  
	private:
		uint32_t setInputCloud(vPointsXYZ* _cloud);
		uint32_t CutCloudroi(vPointsXYZ* inputcloud, PointXYZ m_StartPoint, PointXYZ m_EndPoint, vPointsXYZ* outputcloud);
	
		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI);
		uint32_t CloudSeg(vPointsXYZ* inputcloud,float a_0,int num, std::vector<YZVision::vPointsXYZ>* out_seg, float* num_0);
	};

}
