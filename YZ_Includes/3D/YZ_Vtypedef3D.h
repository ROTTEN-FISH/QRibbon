#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_Vtypedef3D.h
Description: 为基本数据类型，自定义数据类型，数组，指针定义简洁的类型名称
History:     2022-04-16 :  V0.1  :  HRJ  :  创建文件
Note:	     内部资料，请勿外传。
*************************************************/

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "YZ_Includes/public/YZ_Vtypes.h"

namespace YZVision
{
	template <class T> using Vec = std::vector<T>;

	typedef YZVision::PointXYZ				PointsXYZ;					//3D点
	typedef Vec<PointsXYZ>					vPointsXYZ;					//3D点集合
	typedef const vPointsXYZ				c_vPointsXYZ;				//不被改变的3D点集合，常用作入参类型
	typedef YZVision::ROIType				ROIType_E;					//ROI类型
	typedef YZVision::ROIProbeDirection		ROIProbeDirection_E;		//ROI搜索方向
}

