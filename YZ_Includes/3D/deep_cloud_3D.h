/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 deep_cloud_3D.h
Description: 提供点云转深度图的算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-16 :  V1.0  :  SR  :  创建文件；
             2  :  2022-04-19 :  V1.0  :  SR  :  修改继承关系，完善入参校验
			 2  :  2022-04-28 :  V1.0  :  SR  :  修改参数，可选择滤波
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

#include <pcl/search/kdtree.h>//kd树
#include <pcl/surface/mls.h> //最小二乘
#include <pcl/filters/passthrough.h>
#include <pcl/common/transforms.h> //矩阵变换
#include <pcl/filters/voxel_grid.h>//体素下采样
#include <pcl/keypoints/uniform_sampling.h>//均匀采样
#include <pcl/filters/statistical_outlier_removal.h>//统计滤波
#include <pcl/filters/radius_outlier_removal.h>//半径滤波

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
	class Deepcloud_3D 
	{
	public: Deepcloud_3D();
		  ~Deepcloud_3D();


		  /*
		   * 输入参数
		   * inputcloud 输入点云数据
		   * x_0 x方向上的分辨率
		   * y_0 y方向上的分辨率
		   * bool Q 是否要滤波
		   * a_0 滤波阈值
		   */

		  class InputParam
		  {
		  public:
			  vPointsXYZ* inputcloud = NULL;
			  float x_0 = 1;
			  float y_0 = 1;
			  int a_0 = 0;
			  bool Q = false;
		  };

		  /*
		   * 输出参数
		   * outImage 转换后的2D深度图像Mat对象
		   *
		   */
		  class OutputParam
		  {
		  public:
			  Mat outImage;

		  };
		  /*
			  * 函数描述: 实现点云图转深度图.
			  * 返 回 值: 参考YZ_Vwarnings.h
			  */
		  uint32_t deepcloud(InputParam inputParam, OutputParam* outputParam);

	private:
		uint32_t DeepCloud(vPointsXYZ* inputcloud,float x_0, float y_1, bool Q, int a_0, Mat* outImage);

	};

}

