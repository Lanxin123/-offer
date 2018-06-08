#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
};

ListNode *FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2)
{
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);

	int nLegthDif = nLength1 - nLength2;

	ListNode *pListHeadLong = pHead1;
	ListNode *pListHeadShort = pHead2;

	if (nLength2 > nLength1)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLegthDif = nLength2 - nLength1;
	}

	for (int i = 0; i < nLegthDif; ++i)
		pListHeadLong = pListHeadLong->m_pNext;

	while ((pListHeadLong != NULL) && 
		(pListHeadShort != NULL)&&
		(pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	ListNode *pFirstCommonNode = pListHeadLong;
	
	return pFirstCommonNode;
}

unsigned int GetListLength(ListNode *pHead)
{
	unsigned int nLength = 0;
	ListNode *pNode = pHead;
	while (pNode != NULL)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}
	return nLength;
}
