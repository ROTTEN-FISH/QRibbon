#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 segmentation.h
Description: 提供3D分割算法的接口类
History:     2022-04-20 :  V0.1  :  HRJ  :  创建文件
Note:	     内部资料，请勿外传。
*************************************************/

#include "YZ_Vbasic3D.h"

namespace YZVision
{
	class Segmentation: public Basic3D
	{
	public:		

		/* 枚举类(根据不同的点类型拟合直线) */
		enum class LineSegOption
		{
			FIT_LINE_BASE_ON_EDGEPOINTS,
			FIT_LINE_BASE_ON_TURNINGPOINTS
		};


		/* 输入参数结构体 */
		class InputParam
		{
		public:

			/* 输入点云指针 */
			vPointsXYZ* inputCloud = NULL;

			/* 根据不同点云源进行拟合 */
			LineSegOption line_seg_option = LineSegOption::FIT_LINE_BASE_ON_EDGEPOINTS;

			/* 输入搜索方向 */
			ROIProbeDirection serachDir = YZVision::ROIProbeDirection::RIGHT;

			/* 找拐点z方向阈值 */
			float z_threshold;

			/* ROI起点 */
			PointsXYZ m_StartPoint;

			/* ROI终点 */
			PointsXYZ m_EndPoint;

			/* RANSAC距离阈值 */
			double distance_Threshold;

			/* RANSAC最大迭代次数 */
			int max_iteratios;

			/* RANSAC距离权重 */
			double distance_weight;

			/* k近邻数量 */
			int k_nearest_neighbors;
		};

		/* 输出参数结构体 */
		class OutputParam
		{
		public:

			/* 输出模型参数 */
			Vec<float> modelCoeffients;

			/* 输出模型内点 */
			Vec<int> modelInliers;

			/* 输出特征类型 */
			Vec<FeatureType> outputTypes;

			/* xyz角度 */
			Vec<double> xyz_angles;

		};
		
		/* 使用基类中的成员变量 */
		using YZVision::Basic3D::m_input_cloud;
		using YZVision::Basic3D::m_StartPoint;
		using YZVision::Basic3D::m_EndPoint;


		/* 若不加virtual关键字，则继承自Segmentation的派生类则不会调用自身的析构函数 */
		virtual ~Segmentation();

		/* 设置输入点云 */
		uint32_t setInputCloud(vPointsXYZ* _cloud);

		/* 获得ROI内点 */
		uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI);

		/* 对外接口 分割算法（纯虚函数，派生类一定要实现，不然无法实例化对象） */
		virtual uint32_t segment(InputParam inputParam, OutputParam* outputParam) = 0;

	protected:


	};

}
