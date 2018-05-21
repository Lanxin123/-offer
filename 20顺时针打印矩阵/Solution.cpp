#include "stdafx.h"
#include <iostream>

using namespace std;

void PrintMatrixClockwisely(int **numbers,int columns,int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
	{
		return;
	}
	int start = 0;
	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	}
}

void PrintMatrixInCircle(int **numbers,int columns,int rows,int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start;i<=endX;++i)
	{
		int number = numbers[start][i];
		cout << number;
	}
	
	if (start<endY)
	{
		for (int i = start + 1;i<=endY;++i)
		{
			int number = numbers[i][endX];
			cout << number;
		}
	}
	if (start<endY&&start<endX)
	{
		for (int i = endX-1;i>=start;--i)
		{
			int number = numbers[endY][i];
			cout << number;
		}
	}
	if (start<endX&&start<endY-1)
	{
		for (int i = endY-1;i>=start+1;--i)
		{
			int number = numbers[i][start];
			cout << number;
		}
	}
}
//题中顺时针的意思是必须要去经过这几个步骤
//具体边界可能需问问面试官。。。