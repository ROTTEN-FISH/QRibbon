#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 line_plane_distance.h
Description: 提供线面距离算法的实现
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
	class LineToPlaneDis_3D :public Measurement
	{
	public:
		LineToPlaneDis_3D();
		~LineToPlaneDis_3D();

		/* 测量线面之间的距离接口 */
		uint32_t measure(InputParam inputParam, OutputParam* outputParam);

	private:
		/* 线面间距离算子 */
		float lineToPlaneDistance(const Vec<float>* lineCoeffients,
			const Vec<float>* planeCoeffients,
			PointsXYZ referencePoint,
			MeasureDirection dir,
			PointsXYZ& linePoint,
			PointsXYZ& planePoint);

		/* 基于参考点计算面上一点坐标 */
		uint32_t calculatePointInPlaneBasedOnRefPoint(const Vec<float>* planeCoeffients,
			PointsXYZ refPoint,
			MeasureDirection dir,
			PointsXYZ& outputPoint);

		/* 基于参考点计算线上一点坐标 */
		uint32_t calculatePointOnlineBaseOnRefPoint(const Vec<float>* lineCoeffients,
			PointsXYZ refPoint,
			MeasureDirection dir,
			PointsXYZ& outputPoint);

	};


}

