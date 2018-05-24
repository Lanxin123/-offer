#include"stdafx.h"
#include <iostream>
using namespace std;

int MoreThanHalfNum(int *numbers, int length)
{
	if (ChechInvalidArray(numbers,length))
	{
		return 0;
	}

	int result = numbers[0];
	int times = 1;
	for (int i = 1;i<length;++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			times++;
		}
		else
			times--;
	}
	if (!ChechMoreThanHalf(numbers,length,result))
	{
		result = 0;
	}
	return result;
}

bool g_bInputInvalid = false;

bool ChechInvalidArray(int *numbers, int length)
{
	g_bInputInvalid = false;

	if (numbers==NULL && length<=0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}

bool ChechMoreThanHalf(int *numbers, int length, int number)
{
	int times = 0;
	for (int i = 0;i<length;++i)
	{
		if (numbers[i]==number)
		{
			times++;
		}
	}
	bool isMoreThanHalf = true;
	if (times*2<=length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}
	return isMoreThanHalf;
}



