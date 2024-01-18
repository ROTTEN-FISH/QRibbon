#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_edgepoints_3D.h
Description: 提供抽象类feature的接口的具体类EdgePoint
History:     2022-04-18 :  V0.1  :  HRJ  :  创建文件
			 2022-04-19 :  V0.1  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "feature.h"

namespace YZVision
{
	/* class EdgePoint */
	class EdgePoint_3D :public Feature
	{
	public:
		using Feature::m_input_cloud;
		using Feature::m_StartPoint;
		using Feature::m_EndPoint;
		using Feature::m_ProbeDir;
		using Feature::m_PointCloudROI;

		EdgePoint_3D();

		~EdgePoint_3D();

		uint32_t findEdgePoints(InputParam inputParam, OutputParam* outputParam);
		uint32_t findFeature(InputParam inputParam, OutputParam* outputParam);

	private:

		/* sorted points */ 
		vPointsXYZ* m_SortPoint;

		/* output edge points */
		vPointsXYZ* m_EdgePoints;

		/* index of edge points */
		Vec<int32_t>* m_EdgePointIndex;

		/* 根据方向寻找边缘点 */
		uint32_t FindEdgePointRightX(c_vPointsXYZ* pointCloudROI, Vec<int32_t>* vEdgePointIndex, vPointsXYZ* edgePoints);
		uint32_t FindEdgePointLeftX(c_vPointsXYZ* pointCloudROI, Vec<int32_t>* vEdgePointIndex, vPointsXYZ* edgePoints);
		uint32_t FindEdgePointUpY(c_vPointsXYZ* pointCloudROI, Vec<int32_t>* vEdgePointIndex, vPointsXYZ* edgePoints);
		uint32_t FindEdgePointDownY(c_vPointsXYZ* pointCloudROI, Vec<int32_t>* vEdgePointIndex, vPointsXYZ* edgePoints);
	};
}