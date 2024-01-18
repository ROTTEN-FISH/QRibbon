#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_Vwarnings.h
Description: 提供feature的接口
History:     2022-04-18 :  V0.1  :  HRJ  :  创建文件
			 2022-04-18 :  V0.2  :  HRJ  :  class InputParam和class OutputParam
Note:	     内部资料，请勿外传。
*************************************************/

#include "YZ_Vbasic3D.h"

namespace YZVision
{
	class Feature :public Basic3D
	{
	public:

		/* 使用基类中的成员变量 */
		using YZVision::Basic3D::m_input_cloud;
		using YZVision::Basic3D::m_StartPoint;
		using YZVision::Basic3D::m_EndPoint;

		virtual ~Feature()
		{

		}

		/* 输入参数结构体 */
		class InputParam
		{
		public:

			/* 输入点云指针 */
			vPointsXYZ* inputCloud = NULL;

			/* 输入搜索方向 */
			ROIProbeDirection serachDir = YZVision::ROIProbeDirection::RIGHT;

			/* ROI起点 */
			PointsXYZ m_StartPoint;

			/* ROI终点 */
			PointsXYZ m_EndPoint;

			/* z方向阈值，用于找拐点 */
			float z_thres;

		};

		/* 输出参数结构体 */
		class OutputParam
		{
		public:

			/* 输出点云 */
			vPointsXYZ outputPoints;

			/* 输出点的数量 */
			uint32_t outputCounts = 0;

			/* 输出点类型 */
			Vec<FeatureType> outputTypes;

			/* 输出边界点在输入点云中的索引值 */
			Vec<int> edgePointsIndex;

			/* ROI */
			vPointsXYZ roi;
		};

		uint32_t setInputCloud(vPointsXYZ* _cloud);

		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI);

		/* 寻找特征接口 */
		virtual uint32_t findFeature(InputParam inputParam, OutputParam* outputParam) = 0;

		/* 寻找边缘点接口 */
		//virtual uint32_t findEdgePoints(InputParam inputParam, OutputParam* outputParam) = 0;

		/* 寻找拐点 */
		//virtual uint32_t findTurningPoints(InputParam inputParam, OutputParam* outputParam) = 0;

		/* 设置z方向阈值 */
		//virtual uint32_t setThresholdZ(float z_thres) = 0;

	protected:
		/* 排序 */
		uint32_t SortPointsAccordingToRule(vPointsXYZ* inputCloud,
			vPointsXYZ& outputCloud,
			YZVision::SortRule sortRule = YZVision::SortRule::FIRST_Y_THEN_X_ASCENDING);

		/* 规则1 */
		static bool SetSortRule_FirstY(const PointsXYZ pt1, const PointsXYZ pt2);

		/* 规则2 */
		static bool SetSortRule_FirstX(const PointsXYZ pt1, const PointsXYZ pt2);


	};

}
