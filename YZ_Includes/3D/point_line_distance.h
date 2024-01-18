#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 point_line_distance.h
Description: 提供点到点算法的实现
History:     2022-04-22 :  V0.1  :  HRJ  :  创建文件
			 2022-04-22 :  V0.2  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "measurement.h"

#include <Eigen/Core>
#include <Eigen/Dense>

namespace YZVision
{
	class PointToLineDis_3D :public Measurement
	{
	public:
		PointToLineDis_3D();
		~PointToLineDis_3D();

		/* 测量点到线之间的距离 */
		uint32_t measure(InputParam inputParam, OutputParam* outputParam);

	private:
		/* 点到线距离算子 */
		float pointToLineDistance(const PointsXYZ& p1_out_line,
			const Vec<float>& model_coeffients);

		/* 点到线距离的平方 */
		float sqrPointToLineDistance(const Eigen::Vector4f& pt,
			const Eigen::Vector4f& line_pt,
			const Eigen::Vector4f& line_dir);

	};


}