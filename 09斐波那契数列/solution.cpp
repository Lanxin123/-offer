#include "stdafx.h"
#include <iostream>

using namespace std;
long long  Fibonacci(unsigned n)
{
	int result[2] = { 0,1 };
	if (n<2)
	{
		return result[n];
	}
	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 2;
	long long fibN = 0;
	
	for (unsigned i = 0;i<n;i++)
	{
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusOne = fibNMinusTwo;
		fibNMinusTwo = fibN;
	}
	return fibN;
}
