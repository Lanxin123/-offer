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

void PrintFromToBottom(BinaryTreeNode *pTreeNode)
{
	if (pTreeNode==NULL)
	{
		return;
	}
	deque<BinaryTreeNode* > dequeTreeNode;
	
	dequeTreeNode.push_back(pTreeNode);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
	
		cout << pNode->m_nValue;
		
		if (pNode->m_pLeft!=NULL)
		{
			dequeTreeNode.push_back(pNode->m_pLeft);
		}
		if (pNode->m_pRight!=NULL)
		{
			dequeTreeNode.push_back(pNode->m_pRight);
		}
		
	}
}

