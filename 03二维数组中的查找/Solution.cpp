#include "stdafx.h"

bool Find(int* matrix,int rows,int  columns,int number)
{
	bool found = false;
	if (matrix != NULL && rows>0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row<rows&&columns>=0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > number)
				--column;
			else
				++row;
		}
	}
	return found;
}

//行列是针对人的思维而言的，我们把二维数组看做几行几列的矩阵。
//而在内存中是按行存放的，即：a[0][0] a[0][1] a[0][2] a[1][0]......
//
//其中必须指明列。
//
//a[][3]={1,2,3,4,5,6,7}就是a[0][0]=1,a[0][1]=2,a[0][2]=3,a[1][0]=4,a[1][1]=5,a[1][2]=6,a[2][0]=7。