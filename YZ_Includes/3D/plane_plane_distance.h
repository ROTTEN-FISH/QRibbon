#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 plane_plane_distance.h
Description: 提供面面距离算法的实现
History:     2022-04-22 :  V0.1  :  HRJ  :  创建文件
			 2022-04-22 :  V0.2  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "measurement.h"

#include <Eigen/Core>
#include <Eigen/Dense>

#include <pcl/common/distances.h>

namespace YZVision
{
	class PlaneToPlaneDis_3D :public Measurement
	{
	public:
		PlaneToPlaneDis_3D();
		~PlaneToPlaneDis_3D();

		/* 测量面面之间的距离接口 */
		uint32_t measure(InputParam inputParam, OutputParam* outputParam);

	private:

		/* 计算面面之间的距离 */
		float planeToPlaneDistance(const Vec<float>* plane1Coeffients,
			const Vec<float>* plane2Coeffients,
			PointsXYZ referencePoint,
			MeasureDirection dir,
			PointsXYZ& plane1Point,
			PointsXYZ& plane2Point);

		/* 基于参考点计算面上一点坐标 */
		uint32_t calculatePointInPlaneBasedOnRefPoint(const Vec<float>* planeCoeffients,
			PointsXYZ refPoint,
			MeasureDirection dir,
			PointsXYZ& outputPoint);

	};


}