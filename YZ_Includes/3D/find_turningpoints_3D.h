#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_turningpoints.h
Description: 提供抽象类feature的接口的具体类TurningPoint_3D
History:     2022-04-18 :  V0.1  :  HRJ  :  创建文件
			 2022-04-20 :  V0.1  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "feature.h"
#include "find_edgepoints_3D.h"

namespace YZVision
{
	class TurningPoint_3D : public Feature
	{
	public:
		using Feature::m_input_cloud;
		using Feature::m_StartPoint;
		using Feature::m_EndPoint;
		using Feature::m_ProbeDir;
		using Feature::m_PointCloudROI;

		TurningPoint_3D();
		~TurningPoint_3D();



		/* 寻找拐点 */
		uint32_t findTurningPoints(InputParam inputParam, OutputParam* outputParam);

		/* 寻找特征（拐点接口） */
		uint32_t findFeature(InputParam inputParam, OutputParam* outputParam);

	private:
		EdgePoint_3D* p_findEdgePoint;

		/* output turning points */
		vPointsXYZ* m_TurningPoints;

		/* z方向阈值 */	
		float z_Threshold;

		/* 设置z方向阈值 */
		uint32_t setThresholdZ(float z_thres);

		/* +X find turning points */ 
		uint32_t FindTurningPointRightX(c_vPointsXYZ* pointCloudROI,
			Vec<int>* vEdgePointIndex,
			vPointsXYZ* turningPoints);

		/* -X find turning points */ 
		uint32_t FindTurningPointLeftX(c_vPointsXYZ* pointCloudROI,
			Vec<int>* vEdgePointIndex,
			vPointsXYZ* turningPoints);


	};
}