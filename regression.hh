/*
Regression analysis

Copyright 2018 Ahmet Inan <inan@aicodix.de>
*/

#ifndef REGRESSION_HH
#define REGRESSION_HH

namespace DSP {

template <typename TYPE>
class SimpleLinearRegression
{
	TYPE xint_, yint_, slope_;
public:
	SimpleLinearRegression(TYPE *x, TYPE *y, int LEN)
	{
		TYPE avgX(0), avgY(0);
		for (int i = 0; i < LEN; ++i) {
			avgX += x[i];
			avgY += y[i];
		}
		avgX /= LEN;
		avgY /= LEN;
		TYPE varX(0), covXY(0);
		for (int i = 0; i < LEN; ++i) {
			varX += (x[i] - avgX) * (x[i] - avgX);
			covXY += (x[i] - avgX) * (y[i] - avgY);
		}
		xint_ = avgX - avgY * varX / covXY;
		slope_ = covXY / varX;
		yint_ = avgY - slope_ * avgX;
	}
	TYPE xint()
	{
		return xint_;
	}
	TYPE slope()
	{
		return slope_;
	}
	TYPE yint()
	{
		return yint_;
	}
	TYPE operator () (TYPE x)
	{
		return yint_ + slope_ * x;
	}
};

}

#endif

