#include "stdafx.h"
#include <iostream>

using namespace std;

int NumOf1(int n)
{
	unsigned flag = n;
	int count = 0;
	while (flag)
	{
		if (n&flag)
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}
