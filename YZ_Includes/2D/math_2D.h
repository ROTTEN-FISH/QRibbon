/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 find_circle_2D.h
Description: 提供在2D点云中数学运算算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-09 :  V1.0  :  Jiao  :  创建文件；
			 2  :  2022-04-17 :  V1.1  :  Jiao  :  修改func()的输入参数；
			 3  :  2022-05-09 :  V1.2  :  Jiao  :  添加a的变量，添加输出参数b；
*************************************************/
#pragma once


#include "math.h"

#include "aiv.h"
#include "YZ_Includes/public/YZ_Vtypes.h"
#include "YZ_Includes/2D/YZ_Vbasic2D.h"
//#include "../include/YZ_Vtypedef2D.h"

using namespace std;
template <class T> using Vecs = std::vector<T>;


namespace YZVision
{
    class Math_2D : Basic2D
	{
	public:
        Math_2D();
        ~Math_2D();

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
        * Operands：输入图像1
        * Operand：输入图像2
        * add_1：加权系数1
        * add_2：加权系数2
        * operation：操作符号
        * type：roi类型（1为矩形，2为圆形）
        * position：ROI坐标 当type为1时，position[7]为矩形1左上、右上、右下、左下和矩形2左上、右上、右下、左下和坐标；当type为2时，position[0]为第一个圆的圆心坐标，position[1]为第一个圆外接矩形左上角坐标，position[4]为第二个圆的圆心坐标，position[5]为第二个圆外接矩形左上角坐标
		*/
		class InputParam
		{
        public:
            cv::Mat Operands;
            cv::Mat Operand;
            float add_1;
            float add_2;
            String operation;
            int type;
            PointXY position[8];
        };





		/*
        * 输出参数
        *    res：结果图像
		*/
		class OutputParam
		{
        public:
            cv::Mat  res;
		};

        uint32_t static imageMath(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
