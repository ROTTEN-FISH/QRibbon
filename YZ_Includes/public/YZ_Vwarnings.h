#pragma once

/*************************************************
copyright © YZZDH CO., Ltd. 2022 all rights reserved
File name:	 YZ_Vwarnings.h
Description: 提供返回值的警告值
History:     2022-04-18 :  V0.1  :  HRJ  :  创建文件
			 
Note:	     内部资料，请勿外传。
*************************************************/

#define YZ_FAIL											(0)						//函数执行不成功
#define YZ_SUCCESS										(1)						//函数执行成功
#define YZ_INPUT_NULL_PTR								(2)						//参数为指针时，指针为NULL
#define YZ_INPUT_EMPTY_ARRAY							(3)						//参数为数组时，数组长度为0
#define YZ_INPUT_ERR_ENUM								(4)						//参数为枚举类型时，传入了枚举值以外的值
#define YZ_INPUT_WRONG_COEFFIENTS_SIZE					(std::nanf(""))			//输入错误的模型参数
