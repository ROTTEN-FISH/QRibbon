/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 find_line_2D.h
Description: 提供在2D点云中找线算子.
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

using namespace std;
template <class T> using Vecs = std::vector<T>;


namespace YZVision
{
    class FindLine_2D : Basic2D
	{
	public:
        FindLine_2D();
        ~FindLine_2D();

		/*
		* 输入参数
        * raw: 输入图像
        * threshold_lower: 下阈值
        * threshold_upper: 上阈值
        * type: 线类型
        * border: 边缘查找方法
        * ratio：采样比率值
        * subpixel：亚像素方法
        * position：为矩形左上、右上、右下、左下坐标；
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
            int subpixel;
            PointXY position[4];
        };





		/*
		* 输出参数
        *    int code：操作返回值
        *    res：找线处理后的返回图像
        *    samplePts：找线找到的采样点
        *    l： 线段
		*/
		class OutputParam
		{
		public:
			int code;
            cv::Mat  res;
            LineAB l;//线段
            std::vector<PointXY> samplePts;
        };
        uint32_t static FindLine(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
