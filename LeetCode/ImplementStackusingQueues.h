/***********************
*Date:2015.7.22
*Problems:Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*��Ŀ����queueʵ��stack
***********************/
#pragma once
#include <deque>
using namespace std;
class ImplementStackusingQueues
{
public:
	ImplementStackusingQueues();
	~ImplementStackusingQueues();
	/*
		��һ��dequeʵ��
		ÿ�δ���һ��ֵ���������ֵ�Ӷ�β�ŵ���ͷ
		�������������ſ�����һ����ջ��������������������������������
		���Ĳ�������push���Ժ�˳�ν���ͷ���еĴ����β
	*/
	deque<int> q;

	void push(int x) {
		q.push_back(x);
		for (int i = 0;i<q.size()-1;i++){
			q.push_back(q.front());
			q.pop_front();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		q.pop_front();
	}

	// Get the top element.
	int top() {
		return q.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}

};

