#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
	if (!pHead1 || !pHead2 )
	{
		return pHead1 ? pHead2 : pHead1;
	}
	ListNode *pMergeHead = NULL;
	
	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	return pMergeHead;
}