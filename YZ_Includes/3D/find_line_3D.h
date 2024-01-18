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
		/* ʹ����Segmentation�еĳ�Ա���� */
		using Segmentation::m_input_cloud;
		using Segmentation::m_PointCloudROI;
		using Segmentation::m_ProbeDir;
		using Segmentation::m_StartPoint;
		using Segmentation::m_EndPoint;

		LineSegment();
		~LineSegment();

		/* ����ӿ� �ָ��㷨�����麯����������һ��Ҫʵ�֣���Ȼ�޷�ʵ�������� */
		uint32_t segment(InputParam inputParam, OutputParam* outputParam);

		/* ����ӿ� ���þ�����ֵ ����Ҫ����ӿڣ���Ϊ���еĲ���������InputParam���棬��segment�ӿ����������ã�ֱ�ӽ��������ݸ�PCL */
		//uint32_t setDistanceThreshold(double thres);

		/* ����ӿ� �������������� ����Ҫ����ӿڣ���Ϊ���еĲ���������InputParam���棬��segment�ӿ����������� */
		//uint32_t setMaxIterations(int max_iteratios);

	private:
		/* PCL�ķָ��� */ 
		pcl::SACSegmentation<pcl::PointXYZ>* seg;

		/* PCL�ĵ��ƶ��� */
		pcl::PointCloud<pcl::PointXYZ>::Ptr p_PointCloud;

		/* PCL�ĵ���ģ�Ͳ������� */ 
		pcl::ModelCoefficients::Ptr p_ModelCoeffients;

		/* PCL����������� */ 
		pcl::PointIndices::Ptr p_Inliers;

		/* Ѱ�ұ�Ե����� */
		EdgePoint_3D* p_FindEdgePoints;

		/* Ѱ�ҹյ���� */
		TurningPoint_3D* p_FindTurningPoints;

		/* �������������ļнǺ��� */
		static double getAngleOfVector3D(const Vec<float>& v1, const Vec<float>& v2, const bool in_degree = false);
 
	};

}
