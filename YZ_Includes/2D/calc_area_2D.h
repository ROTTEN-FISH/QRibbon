/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 find_circle_2D.h
Description: 提供在2D计算面积算子.
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
    class CalcArea_2D : Basic2D
	{
	public:
        CalcArea_2D();
        ~CalcArea_2D();

		/*
		* 输入参数
        * pts：输入的斑点序列
		*/
		class InputParam
		{
        public:
            std::vector<PointXY> contour;
        };





		/*
		* 输出参数
        *    area:面积
		*/
		class OutputParam
		{
        public:
            double area;
		};

        uint32_t static calc_area(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
