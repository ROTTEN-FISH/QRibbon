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
		/* ʹ����Segmentation�еĳ�Ա���� */
		using Segmentation::m_input_cloud;
		using Segmentation::m_PointCloudROI;
		using Segmentation::m_ProbeDir;
		using Segmentation::m_StartPoint;
		using Segmentation::m_EndPoint;

		CylinderSegment();
		~CylinderSegment();

		/* ����ӿ� �ָ��㷨�����麯����������һ��Ҫʵ�֣���Ȼ�޷�ʵ�������� */
		uint32_t segment(InputParam inputParam, OutputParam* outputParam);

	private:
		/* PCL��Բ���ָ�������ͬ���ߺ��棩 */
		pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal>* seg;

		/* PCL�ĵ��ƶ��� */
		pcl::PointCloud<pcl::PointXYZ>::Ptr p_PointCloud;

		/* PCL�ĵ���ģ�Ͳ������� */
		pcl::ModelCoefficients::Ptr p_ModelCoeffients;

		/* PCL����������� */
		pcl::PointIndices::Ptr p_Inliers;

		/* ���߹��ƶ��� */
		pcl::PointCloud<pcl::Normal>::Ptr p_Normals;
		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal>::Ptr p_NormalEstimation;
		pcl::search::KdTree<pcl::PointXYZ>::Ptr p_Tree;

	};

}