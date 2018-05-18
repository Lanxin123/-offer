#include "stdafx.h"
#include <iostream>

using namespace std;
template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}
template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size()<=0)
	{
		while (stack1.size > 0)
		{
			T& data = stack1.top;//必须是引用，如果不是引用值在pop之后变动。
			stack1.pop();
			stack2.push(data);
			//stack2.push(stack1.top);
			//stack1.pop();
		}
	}
	if (stack2.size()==0)
	{
		throw new exception("queue is empty");
	}
	T head = stack2.top();
	stack2.pop();

	return head;
}
