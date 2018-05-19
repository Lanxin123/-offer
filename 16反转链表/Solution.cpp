#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode *ReverseList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	ListNode *pNext = pHead;
	ListNode *pReverse;
	ListNode *pPre = NULL;
	while (pNode)
	{
		pNext = pNode->m_pNext;
		if (pNext = NULL)
		{
			pReverse = pNode;
		}
		pHead->m_pNext = pPre;
		
		pPre = pHead;
		pHead = pNext;
	}
	return pReverse;
}
