#include "stdafx.h"
#include <iostream>

using namespace std;

double Power(double base, unsigned int exponent)
{
	if (exponent==0)
	{
		return 0;
	}
	if (exponent==1)
	{
		return base;
	}

	double result = Power(base, exponent >> 1);
	result *= result;//一半*一半
	if (exponent & 0x1 == 1)//判断奇偶
		result *= base;
	return result;
}