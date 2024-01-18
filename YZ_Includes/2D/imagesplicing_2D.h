/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 deep_cloud_3D.h
Description: 提供2D图像拼接的算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-22 :  V1.0  :  SR  :  创建文件；	
*************************************************/
#pragma once



#include "YZ_Includes/public/YZ_Vtypes.h"
//#include "YZ_Vexport.h"
#include "YZ_Includes/public/YZ_Vwarnings.h"
#include "YZ_Includes/3D/YZ_Vbasic3D.h"
#include "YZ_Includes/3D/YZ_Vtypedef3D.h"


#include <iostream>
#include <ctime>
#include<fstream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

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
	class Imagesplicing_2D
	{
	public: Imagesplicing_2D();
		  ~Imagesplicing_2D();


		  /*
		   * 输入参数
		   * srcImage1 输入代拼接的图片1
		   * srcImage2 输入代拼接的图片2
		   * min_0 最小矩阵个数
		   * x_0 布尔值 是否去除拼接图像黑边
		   * down 最小阈值
		   * up   最大阈值
		   */

		  class InputParam
		  {
		  public:
			  cv::Mat srcImage1;
			  cv::Mat srcImage2;
			  int min_0 = 1;
			  bool x_0 = 1;
			  int down = 0;
			  int up = 255;


		  };

		  /*
		   * 输出参数
		   * outImage 拼接后的2D图像
		   *
		   */
		  class OutputParam
		  {
		  public:
			  cv::Mat outImage;

		  };
		  /*
			  * 函数描述: 实现2D图像拼接.
			  * 返 回 值: 参考YZ_Vwarnings.h
			  */
		  uint32_t imagesplicing(InputParam inputParam, OutputParam* outputParam);

	private:
		uint32_t removeblack(cv::Mat src, int a, int b, cv::Mat& cropImage);
		uint32_t imagecompression(cv::Mat srcImage1, cv::Mat srcImage2, int min_0, bool x_0, int down, int up, cv::Mat& imageTransform1);
	};

}

