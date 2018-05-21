#include "stdafx.h"
#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int  m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void MirrorRecursively(BinaryTreeNode *pNode)
{
	if (pNode==NULL||(pNode->m_pLeft==pNode->m_pRight))
	{
		return;
	}
	BinaryTreeNode *pTemp;
	pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;
	if (pNode->m_pLeft)
	{
		MirrorRecursively(pNode->m_pLeft);
	}
	if (pNode->m_pRight)
	{
		MirrorRecursively(pNode->m_pRight);
	}
}
