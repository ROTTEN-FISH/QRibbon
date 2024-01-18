#pragma once

#include "segmentation.h"
#include "find_edgepoints_3D.h"
#include "find_turningpoints_3D.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/common/angles.h>
#include <pcl/common/common.h>

namespace YZVision
{
	class LineSegment : public Segmentation
	{
	public:
		/* 使用类Segmentation中的成员变量 */
		using Segmentation::m_input_cloud;
		using Segmentation::m_PointCloudROI;
		using Segmentation::m_ProbeDir;
		using Segmentation::m_StartPoint;
		using Segmentation::m_EndPoint;

		LineSegment();
		~LineSegment();

		/* 对外接口 分割算法（纯虚函数，派生类一定要实现，不然无法实例化对象） */
		uint32_t segment(InputParam inputParam, OutputParam* outputParam);

		/* 对外接口 设置距离阈值 不需要这个接口，因为所有的参数都是在InputParam里面，在segment接口中由我设置，直接将参数传递给PCL */
		//uint32_t setDistanceThreshold(double thres);

		/* 对外接口 设置最大迭代次数 不需要这个接口，因为所有的参数都是在InputParam里面，在segment接口中由我设置 */
		//uint32_t setMaxIterations(int max_iteratios);

	private:
		/* PCL的分割器 */ 
		pcl::SACSegmentation<pcl::PointXYZ>* seg;

		/* PCL的点云对象 */
		pcl::PointCloud<pcl::PointXYZ>::Ptr p_PointCloud;

		/* PCL的点云模型参数对象 */ 
		pcl::ModelCoefficients::Ptr p_ModelCoeffients;

		/* PCL的索引点对象 */ 
		pcl::PointIndices::Ptr p_Inliers;

		/* 寻找边缘点对象 */
		EdgePoint_3D* p_FindEdgePoints;

		/* 寻找拐点对象 */
		TurningPoint_3D* p_FindTurningPoints;

		/* 计算两个向量的夹角函数 */
		static double getAngleOfVector3D(const Vec<float>& v1, const Vec<float>& v2, const bool in_degree = false);
 
	};

}
