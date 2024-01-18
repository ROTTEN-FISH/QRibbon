/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	planeness_cloud_3D.h
Description: 提供点云平整度计算的算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-20 :  V1.0  :  SR  :  创建文件；
             2  :  2022-04-21 :  V1.0  :  SR  :  修改roi调用bug；
*************************************************/
#pragma once



#include "YZ_Includes/public/YZ_Vtypes.h"
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
	class Planenesscloud_3D :public Basic3D
	{
	public: Planenesscloud_3D();
		  ~Planenesscloud_3D();

		  using Basic3D::m_PointCloudROI;
		  /*
		   * 输入参数
		   * inputcloud 输入点云数据
		   * m_StartPoint roi左下坐标
		   * m_StartPoint roi右下坐标
		   * r_0 采样半径
		   */

		  class InputParam
		  {
		  public:
			  YZVision::vPointsXYZ* inputcloud = NULL ;
			  YZVision::PointXYZ m_StartPoint;
			  YZVision::PointXYZ m_EndPoint ;
			  float r_0 = 1;
		  };

		  /*
		   * 输出参数
		   * outputcloud roi点云数据
		   * min_p 最小距离
		   * max_p 最大距离
		   * sum_p 距离之和
		   *
		   */
		  class OutputParam
		  {
		  public:
			  YZVision::vPointsXYZ outputcloud;
			  float min_p = 0;
			  float max_p = 0;
			  float sum_p = 0;
		  };
		  /*
			  * 函数描述: 实现点云平整度计算.
			  * 返 回 值: 参考YZ_Vwarnings.h
			  
		  */
		  uint32_t planenesscloud(InputParam inputParam, OutputParam* outputParam);

	private:
		uint32_t Planenessroi(vPointsXYZ* inputcloud,PointXYZ m_StartPoint, PointXYZ m_EndPoint, vPointsXYZ* outputcloud);
		uint32_t setInputCloud(vPointsXYZ* _cloud);
		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI);
		uint32_t Planenesscloud(c_vPointsXYZ* inputcloud, float r_0, float &min_p, float &max_p, float &sum_p);

	};

}

