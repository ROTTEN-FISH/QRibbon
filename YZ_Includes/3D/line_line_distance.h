#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 line_line_distance.h
Description: 提供异面直线距离算法的实现
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
	class LineToLineDis_3D :public Measurement
	{
	public:
		LineToLineDis_3D();
		~LineToLineDis_3D();

		/* 测量异面直线之间的距离接口 */
		uint32_t measure(InputParam inputParam, OutputParam* outputParam);

	private:
		/* 计算两条异面直线之间的距离*/
		float lineToLineDistance(const Vec<float>& line_a,
			const Vec<float>& line_b,
			PointsXYZ& pt1,
			PointsXYZ& pt2);

	};


}