#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct BinaryTreeNode 
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
	if (pRoot == NULL)
		return;
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot,expectedSum,path,currentSum);
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum, vector<int>& path, int& currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf)
	{
		cout << "A path is found";
		auto iter = path.begin();
		for (;iter != path.end();++iter)
		{
			cout << *iter;
		}
	}

	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	currentSum -= pRoot->m_nValue;
	path.pop_back();
}










