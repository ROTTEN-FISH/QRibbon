#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 point_point_distance.h
Description: 提供点到点算法的实现
History:     2022-04-22 :  V0.1  :  HRJ  :  创建文件
			 2022-04-22 :  V0.2  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "measurement.h"

namespace YZVision
{
	class PointToPointDis_3D :public Measurement
	{
	public:
		PointToPointDis_3D();
		~PointToPointDis_3D();

		/* 测量点到点之间的距离 */
		uint32_t measure(InputParam inputParam, OutputParam* outputParam);

	private:
		/* 欧式距离的平方 */
		float squaredEuclideanDistance(const PointsXYZ& p1,
			const PointsXYZ& p2);

		/* 欧式距离 */ 
		float euclideanDistance(const PointsXYZ& p1,
			const PointsXYZ& p2);

	};


}
