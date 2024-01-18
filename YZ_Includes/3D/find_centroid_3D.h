#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_centroid_3D.h
Description: 提供抽象类feature的接口的具体类Centroid_3D
History:     2022-04-20 :  V0.1  :  HRJ  :  创建文件
			 2022-04-20 :  V0.2  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "feature.h"

namespace YZVision
{
	/* class Centroid_3D */
	class Centroid_3D : public Feature
	{
	public:
		using Feature::m_input_cloud;
		using Feature::m_StartPoint;
		using Feature::m_EndPoint;
		using Feature::m_ProbeDir;
		using Feature::m_PointCloudROI;

		Centroid_3D();
		~Centroid_3D();

		/* 找质心接口 */
		uint32_t findFeature(InputParam inputParam, OutputParam* outputParam);



	private:

		/* calculate 3D Centroid */ 
		uint32_t calculate3DCentroid(c_vPointsXYZ* inputCloud,
			PointsXYZ& output_Centroid);


	};
}
