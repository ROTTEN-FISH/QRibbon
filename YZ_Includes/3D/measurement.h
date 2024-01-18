#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 measure.h
Description: 提供Measurement的接口
History:     2022-04-22 :  V0.1  :  HRJ  :  创建文件
			 2022-04-22 :  V0.2  :  HRJ  :  class InputParam和class OutputParam
Note:	     内部资料，请勿外传。
*************************************************/

#include "YZ_Vbasic3D.h"

namespace YZVision
{
	class Measurement :public Basic3D
	{
	public:

		/* 测量方向 */
		enum class MeasureDirection
		{
			SHORTEST_DIRECTION,
			PARALLEL_TO_X_AXIS,
			PARALLEL_TO_Y_AXIS,
			PARALLEL_TO_Z_AXIS
		};

		/* 输入参数结构体 */
		class InputParam
		{
		public:
			/* 输入模型参数 */
			Vec<float> modelCoeffients;

			/* 输入模型内点 */
			Vec<int> modelInliers;

			/* 点1 */
			PointsXYZ pt1;

			/* 点2 */
			PointsXYZ pt2;

			/* 直线外一点 */
			PointsXYZ pt_out_line;

			/* 平面外一点 */
			PointsXYZ pt_out_plane;

			/* 异面直线1 */
			Vec<float> line1Coeffients;

			/* 异面直线2 */
			Vec<float> line2Coeffients;

			/* 平面外的直线参数 */
			Vec<float> line_out_plane;

			/* 平面1参数 */
			Vec<float> plane1Coeffients;

			/* 平面2参数 */
			Vec<float> plane2Coeffients;

			/* 参考点 */
			PointsXYZ ref_pt;

			/* 测量方向 */
			MeasureDirection measure_dir;

		};

		/* 输出参数结构体 */
		class OutputParam
		{
		public:
			/* 距离值 */
			float distance;

			/* 异面直线1上一点 */
			PointsXYZ pt1_on_line;

			/* 异面直线2上一点 */
			PointsXYZ pt2_on_line;

			/* 计算线面距离时输出的线上一点 */
			PointsXYZ pt3_on_line;

			/* 计算线面距离时输出的面上一点 */
			PointsXYZ pt4_on_plane;

			/* 计算面面距离时输出的面上一点 */
			PointsXYZ pt5_on_plane;

			/* 计算面面距离时输出的面上一点 */
			PointsXYZ pt6_on_plane;

		};

		/* 虚析构函数 */
		virtual ~Measurement() {};

		/* 设置输入点云(挖的坑，得实现) */
		uint32_t setInputCloud(vPointsXYZ* _cloud)
		{
			return YZ_FAIL;
		}

		/* 获得ROI内点(挖的坑，得实现) */
		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI)
		{
			return YZ_FAIL;
		}

		/* 对外接口（纯虚函数）测量 */
		virtual uint32_t measure(InputParam inputParam, OutputParam* outputParam) = 0;

	protected:


	};
}