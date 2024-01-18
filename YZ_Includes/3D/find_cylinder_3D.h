#pragma once

#include "segmentation.h"

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/features/normal_3d.h>

namespace YZVision
{
	class CylinderSegment : public Segmentation
	{
	public:
		/* 使用类Segmentation中的成员变量 */
		using Segmentation::m_input_cloud;
		using Segmentation::m_PointCloudROI;
		using Segmentation::m_ProbeDir;
		using Segmentation::m_StartPoint;
		using Segmentation::m_EndPoint;

		CylinderSegment();
		~CylinderSegment();

		/* 对外接口 分割算法（纯虚函数，派生类一定要实现，不然无法实例化对象） */
		uint32_t segment(InputParam inputParam, OutputParam* outputParam);

	private:
		/* PCL的圆柱分割器（不同于线和面） */
		pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal>* seg;

		/* PCL的点云对象 */
		pcl::PointCloud<pcl::PointXYZ>::Ptr p_PointCloud;

		/* PCL的点云模型参数对象 */
		pcl::ModelCoefficients::Ptr p_ModelCoeffients;

		/* PCL的索引点对象 */
		pcl::PointIndices::Ptr p_Inliers;

		/* 法线估计对象 */
		pcl::PointCloud<pcl::Normal>::Ptr p_Normals;
		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal>::Ptr p_NormalEstimation;
		pcl::search::KdTree<pcl::PointXYZ>::Ptr p_Tree;

	};

}