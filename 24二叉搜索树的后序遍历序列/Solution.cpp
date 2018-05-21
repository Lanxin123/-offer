#include "stdafx.h"
#include <iostream>
#include <deque>

using namespace std;

struct BinaryTreeNode 
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

bool VerifySqueneceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
	{
		return false;
	}
	
	int root = sequence[length - 1];

	int i = 0;
	for (;i<length-1;++i)
	{
		if (sequence[i]>root)
		{
			break;
		}
	}

	int j = i;
	for (;j<length-1;++j)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}

	int j = i;
	for (;j<length-1;++j)
	{
		if (sequence[j]<root)
		{
			return false;
		}
	}

	bool left = true;
	if (i>0)
	{
		left = VerifySqueneceOfBST(sequence, i);
	}

	bool right = true;
	if (i<length - 1)
	{
		right = VerifySqueneceOfBST(sequence + i, length - i - 1);
	}
	return left&&right;
}
