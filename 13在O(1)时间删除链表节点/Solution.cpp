#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
	{
		return;
	}
	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode *pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		
		delete(pNext);
		pNext = NULL;//防止野指针
	}
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		// 这里为什么不能够直接写 next = null;
		// 因为next = null 并不意味着 current 访问不到 current.next,还是可以的，
		// 所以要写为 current.next = null, 这样才能保证删除最后一个节点
	}
}

