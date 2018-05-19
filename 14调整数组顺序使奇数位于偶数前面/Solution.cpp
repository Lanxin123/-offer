#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead==NULL || k == 0)
	{
		return 0;
	}
	ListNode *pAhead = pListHead;
	ListNode *pBehind = pListHead;

	for (int i = 0; i < k; ++i)
	{
		if (pAhead->m_pNext != NULL)
		{
			pAhead = pAhead->m_pNext;
		}
		else
		{
			return 0;
		}
	}

	while (pAhead->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}
