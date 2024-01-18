#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_Vtypes.h
Description: 提供基本数据类型的定义以及自定义数据类型
History:     2022-04-16 :  V0.1  :  HRJ  :  创建文件
Note:	     内部资料，请勿外传。
*************************************************/

#include <stdint.h>

#include "YZ_Vwarnings.h"

namespace YZVision
{
	/* PointXYZ */
	struct PointXYZ
	{
		float x;
		float y;
		float z;
		PointXYZ() :
			x(0.f),
			y(0.f),
			z(0.f) {}

		unsigned int setPoint(float _x, float _y, float _z)
		{
			x = _x;
			y = _y;
			z = _z;

			return YZ_SUCCESS;

		}
	};

	/* PointXY */
	struct PointXY
	{
		float x;
		float y;

		PointXY() :
			x(0.f),
			y(0.f) {}


		unsigned int setPoint(float _x, float _y)
		{
			x = _x;
			y = _y;


			return YZ_SUCCESS;

		}
	};

	/* FeatureType */
	enum class FeatureType
	{
		POINT = 1,
		LINE,
		PLANE,
		CYLINDER
	};

	/* ROIProbeDirection */
	enum class ROIProbeDirection
	{
		RIGHT = 1,
		LEFT,
		DOWN,
		UP,
		BACK,
		FRONT
	};

	/* ROIType */
	enum class ROIType
	{
		WINDOW = 1,
		BOX = 2
	};

	/* SortRule */ 
	enum class SortRule
	{
		FIRST_X_THEN_Y_ASCENDING,
		FIRST_Y_THEN_X_ASCENDING
	};

}


