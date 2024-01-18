/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 read_cloud_3D.h
Description: 提供点云读取方式，从txt或者pcd文件读取.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-18 :  V1.0  :  SR  :  创建文件；
*************************************************/
#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include "YZ_Includes/public/YZ_Vtypes.h"
#include "YZ_Vtypedef3D.h"





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

using namespace std;

using namespace cv;

using namespace cv::xfeatures2d;
namespace YZVision
{
	class Readcloud_3D
	{
	public: 
		Readcloud_3D();
		~Readcloud_3D();


		  /*
		   * 输入参数
		   * read 读取txt 或pcd文件 路径
		   * save 保存pcd路径
		   * 
		   */

		  class InputParam
		  {
		  public:
			  string read;
			  string save;

		  };

		  /*
		   * 输出参数
		   * outputcloud 输出点云数据保存的数组
		   *
		   */
		  class OutputParam
		  {
		  public:
			  vPointsXYZ outputcloud;

		  };
		  /*
			  * 函数描述: 实现点云图的读取.
			  * 返 回 值: 参考YZ_Vwarnings.h
			  */
		  uint32_t readcloud(InputParam inputParam, OutputParam* outputParam);

	private:
		uint32_t TXT_PCD(string read,string save);
		uint32_t PCDTocloudarr(string save, vPointsXYZ* outputcloud);

	};

}

