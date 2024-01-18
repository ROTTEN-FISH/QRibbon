/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 find_circle_2D.h
Description: 提供在2D点云中找圆算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-09 :  V1.0  :  Jiao  :  创建文件；
			 2  :  2022-04-17 :  V1.1  :  Jiao  :  修改func()的输入参数；
			 3  :  2022-05-09 :  V1.2  :  Jiao  :  添加a的变量，添加输出参数b；
*************************************************/
#pragma once


#include "math.h"

#include "aiv.h"
#include "YZ_Includes/public/YZ_Vtypes.h"
#include "YZ_Includes/public/YZ_Vwarnings.h"
#include "YZ_Vbasic2D.h"
//#include "../include/YZ_Vtypedef2D.h"

using namespace std;
template <class T> using Vecs = std::vector<T>;


namespace YZVision
{
	class FindCircle_2D : Basic2D
	{
	public:
		FindCircle_2D();
		~FindCircle_2D();

		/*
		* 输入参数
        * raw: 输入图像
        * threshold_lower: 下阈值
        * threshold_upper: 上阈值
        * type: 圆类型
        * border: 边缘查找方法
        * ratio：采样比率值
        * radius_min：最小半径
        * radius_max：最大半径
        * circleCenter：roi查找圆心
        * innerRadius：roi查找的内圆半径
        * outerRadius：roi查找的外圆半径
		*/
		class InputParam
		{
        public:
            cv::Mat raw;
			int threshold_lower;
			int threshold_upper;
			int type;
			int border;
			int ratio;
			int radius_min;
            int radius_max;
            PointXY circleCenter;
            float innerRadius;
            float outerRadius;
        };





		/*
		* 输出参数
        *    int code：操作返回值
        *    res：找圆处理后的返回图像
        *    samplePts：圆1找到的采样点
        *    samplePts2： 圆2找到的采样点（只有设置找圆环才有）
        *    circle1：圆1的数据
        *    circle2：圆2的数据（只有设置找圆环才有）
		*/
		class OutputParam
		{
		public:
			int code;
            cv::Mat  res;
			Vecs<QPoint> samplePts;
			Vecs<QPoint> samplePts2;
			CircleXYR circle1;
			CircleXYR circle2;
		};

        uint32_t static FindCircle(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
