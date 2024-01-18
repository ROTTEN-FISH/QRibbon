#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 transformation.h
Description: 提供transformation的接口
History:     2022-04-22 :  V0.1  :  HRJ  :  创建文件
Note:	     内部资料，请勿外传。
*************************************************/

#include "YZ_Vbasic3D.h"

namespace YZVision
{
	class Transformation: public Basic3D
	{
	public:
		/* 输入参数结构体 */
		class InputParam
		{
		public:
			/* 输入点云 */
			vPointsXYZ *input_cloud = NULL;

			/* 锚点坐标 */
			PointsXYZ anchor_point;

			/* 与xyz轴的夹角 */
			float angle_xyz[3];

			/* 是否手动输入 */
			bool is_manual;

		};

		/* 输出参数结构体 */
		class OutputParam
		{
		public:
			/* 变换后的点云 */
			vPointsXYZ trans_point_cloud;

		};

		/* 虚析构函数 */
		virtual ~Transformation() {};

		/* Set input cloud. */
		uint32_t setInputCloud(vPointsXYZ* _cloud)
		{
			return YZ_FAIL;
		}

		/* 获得ROI内点 */
		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI)
		{
			return YZ_FAIL;
		}

		/* 转换函数（对外接口）*/
		virtual uint32_t transform(InputParam inputParam, OutputParam* outputParam) = 0;

	protected:

	};
}