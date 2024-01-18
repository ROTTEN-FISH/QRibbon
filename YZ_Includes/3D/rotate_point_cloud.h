#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 rotate_point_cloud.h
Description: 提供点云变换算法的实现
History:     2022-04-24 :  V0.1  :  HRJ  :  创建文件
			 2022-04-24 :  V0.2  :  HRJ  :  debug完成
Note:	     内部资料，请勿外传。
*************************************************/

#include "transformation.h"

#include <Eigen/Core>
#include <Eigen/Dense>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>

namespace YZVision
{
	class RotatePointCloud : public Transformation
	{
	public:
		RotatePointCloud();
		~RotatePointCloud();

		/* 点云旋转算法 */
		uint32_t transform(InputParam inputParam, OutputParam* outputParam);



	private:

		/* 旋转点云算法 */
		uint32_t rotatePointCloudAccordingToAngleXYZ(const vPointsXYZ* inputCloud,
			const float* angle,
			vPointsXYZ& outputCloud);

		/* 计算点云旋转矩阵 */
		uint32_t calculateTransformMatrix(const float* angle,
			float(*transform_Matrix)[4]);

		/* 旋转点云算法 */
		uint32_t rotateMovePointCloud(const vPointsXYZ* inputCloud,
			float(*transform_Matrix)[4],
			vPointsXYZ& outputCloud);

		/* 计算点云变换矩阵（分别输出三个旋转矩阵）*/
		uint32_t calculateTransformMatrix(PointsXYZ anchorPoint,
			const float* angle,
			float(*transformX_Matrix)[4],
			float(*transformY_Matrix)[4],
			float(*transformZ_Matrix)[4]);


	};


}
