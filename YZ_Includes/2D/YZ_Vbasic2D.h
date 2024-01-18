#pragma once

#include "YZ_Includes/public/YZ_Vtypes.h"

namespace YZVision
{
    class Basic2D
    {
    public:
        enum Code 
        {
            SUCCESS = 0,
            TOO_LESS_POINTS = -1,
            FAIL = 1
        };

		typedef struct CircleXYR
		{
			float x;
			float y;
			float r;
			CircleXYR():
				x(0.f),
				y(0.f),
				r(0.f) {}

			unsigned int setCircle(float _x, float _y, float _r)
			{
				x = _x;
				y = _y;
				r = _r;

				return YZ_SUCCESS;
			}
		}CircleXYR;

        typedef struct PointXY
        {
            float x;
            float y;

            PointXY() :
                x(0.f),
                y(0.f) {}
            PointXY(float _x,float _y) :x(_x),y(_y){}
            unsigned int setPoint(float _x, float _y)
            {
                x = _x;
                y = _y;
                return YZ_SUCCESS;
            }
        }PointXY;
        typedef struct LineAB
        {
            PointXY a;
            PointXY b;
            LineAB():
                a(PointXY()),
                b(PointXY()){}
            LineAB(PointXY _a,PointXY _b):
                a(_a),
                b(_b){}

        }LineAB;


    };
}

