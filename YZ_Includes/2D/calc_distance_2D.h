/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 find_circle_2D.h
Description: 提供在2D计算长度算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-20 :  V1.0  :  Jiao  :  创建文件；
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
    class CalcDistance_2D : Basic2D
	{
	public:
        CalcDistance_2D();
        ~CalcDistance_2D();

		/*
		* 输入参数
        * startpoint：起始点
        * endpoint：终点
		*/
		class InputParam
		{
        public:
            cv::Mat raw;
            PointXY startpoint;
            PointXY endpoint;
        };





		/*
		* 输出参数
        *    res:结果图像
        *    code：操作码
        *    l:长度
		*/
		class OutputParam
		{
        public:
            cv::Mat res;
            int code;
            double l;
		};

        uint32_t static calc_distance(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
