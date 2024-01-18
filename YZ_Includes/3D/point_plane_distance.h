#pragma once
/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 point_plane_distance.h
Description: 提供点到面算法的实现
History:     2022-04-22 :  V0.1  :  HRJ  :  创建文件
			 2022-04-22 :  V0.2  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "measurement.h"

namespace YZVision
{
	class PointToPlaneDis_3D :public Measurement
	{
	public:
		PointToPlaneDis_3D();
		~PointToPlaneDis_3D();

		/* 测量点到面之间的距离接口 */
		uint32_t measure(InputParam inputParam, OutputParam* outputParam);

	private:
		/* 点到面之间的距离算子 */
		float pointToPlaneDistance(const PointsXYZ& p1_out_plane,
			const Vec<float>& model_coeffients);

	};


}
