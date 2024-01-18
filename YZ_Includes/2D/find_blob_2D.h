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
#include "YZ_Includes/2D/YZ_Vbasic2D.h"

using namespace std;
template <class T> using Vecs = std::vector<T>;


namespace YZVision
{
    class FindBlob_2D : Basic2D
	{
	public:
        FindBlob_2D();
        ~FindBlob_2D();

		/*
        1. raw：输入图像
        2. int type：斑点检测类型（0在范围内，1在范围外）
        3. int threshold_lower：下阈值
        4. int threshold_upper：上阈值
        5. bool border：是否排除边界
        6. bool fill：是否填充斑点漏洞
        7. int type_p：roi类型（1为矩形，2为圆形）
        8. QPointF position[]：ROI坐标，当type为1时，position[3]为矩形左上、右上、右下、左下坐标；当type为2时，position[1]分别为圆心、圆外界矩形左上角坐标
        9. bool width_f：是否开启宽度过滤
        10. int width_f_min：宽度过滤最小值
        11. int width_f_max：宽度过滤最大值
        12. bool height_f：是否开启高度过滤
        13. int height_f_min：高度过滤最小值
        14. int height_f_max：高度过滤最大值
        15. bool area：是否开启面积过滤
        16. int area_min：面积过滤最小值
        17. int area_max：面积过滤最大值
        18. bool number：是否开启数量过滤
        19. int number_min：数量过滤最小值
        20. int number_max:数量过滤最大值
		*/
		class InputParam
		{
        public:
            cv::Mat raw;
            int threshold_lower;
			int threshold_upper;
            int type;
            bool border;
            bool fill;
            int type_p;
            PointXY position[4];
            bool width_f;
            int width_f_min;
            int width_f_max;
            bool height_f;
            int height_f_min;
            int height_f_max;
            bool area;
            int area_min;
            int area_max;
            bool number;
            int number_min;
            int number_max;

        };





		/*
		* 输出参数
        1. res: blob处理后的返回图像
        2. std::vector<std::vector<QPoint>> resContours：blob找到的所有斑点序列
        3. std::vector<double> areas： 每个序列的面积
        4. std::vector<double> widths：每个序列的宽度
        5. std::vector<double> heights：每个序列的高度
		*/
		class OutputParam
		{
		public:
            cv::Mat  res;
            std::vector<std::vector<PointXY>> resContours;
            std::vector<double> areas;
            std::vector<double> widths;
            std::vector<double> heights;
        };
        uint32_t static FindBlob(InputParam inputParam, OutputParam *outputParam);

	private:
		
	};
}
