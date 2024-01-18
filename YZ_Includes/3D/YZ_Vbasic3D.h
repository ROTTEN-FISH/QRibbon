#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_Vbasic.h
Description: 提供所有3D类的抽象基类
History:     2022-04-16 :  V0.1  :  HRJ  :  创建文件
		     2022-04-18 :  V0.2  :  HRJ  :  添加ROI
Note:	     内部资料，请勿外传。
*************************************************/

#include "YZ_Vtypedef3D.h"

namespace YZVision
{
	/* class Basic3D */ 
	class Basic3D
	{
	public:

		/* Destructor. */
		virtual ~Basic3D()
		{
			if (m_input_cloud)
			{
				delete m_input_cloud;
			}
		}

		/* Set input cloud. */
		virtual uint32_t setInputCloud(vPointsXYZ* _cloud) = 0;

		/* 获得ROI内点 */
		virtual uint32_t ObtainROIPoint(vPointsXYZ& pointCloudROI) = 0;

		/*************************************************
		Function name: 	getPointStart
		Description:	获得ROI起点坐标
		Input params:	无
		Output Params:	无
		Return:			点
		Note:			备注
		*************************************************/
		PointsXYZ getPointStart()
		{
			PointsXYZ pt;
			pt.x = this->m_StartPoint.x;
			pt.y = this->m_StartPoint.y;
			pt.z = this->m_StartPoint.z;
			return pt;
		}

		/*************************************************
		Function name:	getPointEnd
		Description:	获得ROI终点坐标
		Input params:	无
		Output Params:	无
		Return:			点
		Note:			备注
		*************************************************/
		PointsXYZ getPointEnd()
		{
			PointsXYZ pt;
			pt.x = this->m_EndPoint.x;
			pt.y = this->m_EndPoint.y;
			pt.z = this->m_EndPoint.z;
			return pt;
		}

		/*************************************************
		Function name:	getROIType
		Description:	获得ROI类型
		Input params:	无
		Output Params:	无
		Return:			枚举ROI类型
		Note:			备注
		*************************************************/
		ROIType_E getROIType()
		{
			return m_ROIType;
		}

		/*************************************************
		Function name:	getProbeDirection
		Description:	获得ROI中的搜索方向
		Input params:	无
		Output Params:	无
		Return:			枚举搜索方向
		Note:			备注
		*************************************************/
		ROIProbeDirection_E getProbeDirection()
		{
			return m_ProbeDir;
		}

		/*************************************************
		Function name:	setPointStart
		Description:	设置起点坐标
		Input params:	PointsXYZ m_Point
		Output Params:	无
		Return:			YZ_SUCCESS
		Note:			备注
		*************************************************/
		uint32_t setPointStart(PointsXYZ m_Point)
		{
			this->m_StartPoint = m_Point;
			return YZ_SUCCESS;
		}

		/*************************************************
		Function name:	setPointStart(重载)
		Description:	设置起点坐标
		Input params:	float x, float y, float z
		Output Params:	无
		Return:			YZ_SUCCESS
		Note:			备注
		*************************************************/
		uint32_t setPointStart(float x, float y, float z)
		{
			this->m_StartPoint.x = x;
			this->m_StartPoint.y = y;
			this->m_StartPoint.z = z;

			return YZ_SUCCESS;
		}

		/*************************************************
		Function name:	setPointEnd
		Description:	设置ROI终点坐标
		Input params:	PointsXYZ m_Point
		Output Params:	无
		Return:			YZ_SUCCESS
		Note:			备注
		*************************************************/
		uint32_t setPointEnd(PointsXYZ m_Point)
		{
			this->m_EndPoint = m_Point;
			return YZ_SUCCESS;
		}

		/*************************************************
		Function name:	setPointEnd（重载）
		Description:	设置ROI终点坐标
		Input params:	float x, float y, float z
		Output Params:	无
		Return:			YZ_SUCCESS
		Note:			备注
		*************************************************/
		uint32_t setPointEnd(float x, float y, float z)
		{
			this->m_EndPoint.x = x;
			this->m_EndPoint.y = y;
			this->m_EndPoint.z = z;

			return YZ_SUCCESS;
		}

		/*************************************************
		Function name:	setROIType
		Description:	设置ROI类型
		Input params:	ROIType m_Type
		Output Params:	无
		Return:			YZ_SUCCESS
		Note:			备注
		*************************************************/
		uint32_t setROIType(ROIType m_Type)
		{
			this->m_ROIType = m_Type;
			return YZ_SUCCESS;
		}

		/*************************************************
		Function name:	setProbeDirection
		Description:	设置搜索方向
		Input params:	ROIProbeDirection m_Dir
		Output Params:	无
		Return:			YZ_SUCCESS
		Note:			备注
		*************************************************/
		uint32_t setProbeDirection(ROIProbeDirection m_Dir)
		{
			this->m_ProbeDir = m_Dir;
			return YZ_SUCCESS;
		}



	protected:

		/* The input point cloud dataset. */
		vPointsXYZ* m_input_cloud;

		/* ROI */
		vPointsXYZ* m_PointCloudROI;

		/* m_StartPoint */ 
		PointsXYZ m_StartPoint;

		/* m_EndPoint */ 
		PointsXYZ m_EndPoint;

		/* ROIType */ 
		ROIType_E m_ROIType;

		/* ROIProbeDirection */ 
		ROIProbeDirection_E m_ProbeDir;

		/* ROI points' number */ 
		int m_ValidPointsNum;

	};
}
