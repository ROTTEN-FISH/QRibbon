/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 find_line_2D.h
Description: 提供在2D模板匹配算子.
Note:	     内部资料，请勿外传.
History:     1  :  2022-04-21 :  V1.0  :  Jiao  :  创建文件；
*************************************************/
#pragma once


#include "math.h"
#include "aiv.h"
#include "YZ_Includes/public/YZ_Vtypes.h"
#include "YZ_Includes/2D/YZ_Vbasic2D.h"

using namespace std;
template <class T> using Vecs = std::vector<T>;


namespace YZVision
{
    class MatchTemplate_2D : Basic2D
	{
	public:
        //单个特征信息
        struct FeatureStruct
        {
            int x;
            int y;
            int lbl;
        };
        //用于存放单个模板匹配结果
        struct temStruct{
            int x;
            int y;
            float similarity;
            int w;
            int h;
            std::vector<FeatureStruct> features;
            float angle;
            float scale;
        };
        MatchTemplate_2D();
        ~MatchTemplate_2D();

		/*
            bool train_changed：是否需要更换模板
            QImage train：训练图像
            QImage search：被查找的图像
            int rotate：旋转选项（0为无旋转，3为360度）
            int rotate_min：旋转范围最小值
            int rotate_max：旋转范围最大值
            int zoom：缩放选项（0为无缩放，3为自定义缩放比）
            qreal zoom_min：缩放范围最小值
            qreal zoom_max：缩放范围最大值
            int type：算法类型（0为相关算法，1为边缘匹配，2为轮廓匹配）
            int scores：最小匹配分数
            int number：匹配数量
            int type1：训练图像roi类型（1为矩形，2为圆形）
            int type2：被查找图像roi类型（1为矩形，2为圆形）
            QPointF position[]：训练图像type为1时，position[3]为矩形左上、右上、右下、左下坐标；当type为2时，position[1]分别为圆心、圆外界矩形左上角坐标。被查找图像type为1时，position[4][5][6][7]为矩形左上、右上、右下、左下坐标；type为2时，position[4][5]分别为圆心、圆外界矩形左上角坐标

		*/
		class InputParam
		{
        public:
            bool train_changed;
            cv::Mat train;
            cv::Mat search;
            int rotate;
            int rotate_min;
            int rotate_max;
            int zoom;
            double zoom_min;
            double zoom_max;
            int type;
            int scores;
            int number;
            int type1;
            int type2;
            PointXY position[8];
        };





		/*
		* 输出参数
        QImage res：操作返回显示的结果
        int code：返回操作数
        std::vector<temStruct> tems：返回所有模板匹配的信息
		*/
		class OutputParam
		{
		public:
            cv::Mat res;
            int code;
            std::vector<temStruct> tems;
        };
        uint32_t static MatchTemplate(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
