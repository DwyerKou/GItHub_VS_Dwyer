/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

ʵ��һ����Сջ
����������ջ��һ�����ǳ���ջ����һ����ÿ�γ��ֵ���Сֵ
*/
#pragma once
#include "LeetCode.h"
class MinStack
{
public:
	MinStack();
	~MinStack();

	stack<int> m_normalStack;
	stack<int> m_minStack;

	void push(int x) {
		if (m_normalStack.empty())
			m_minStack.push(x);
		else if (x <= m_minStack.top())
			m_minStack.push(x);
		m_normalStack.push(x);
	}

	void pop() {
		if (m_normalStack.top() == m_minStack.top())
			m_minStack.pop();
		m_normalStack.pop();
	}

	int top() {
		return m_normalStack.top();
	}

	int getMin() {
		return m_minStack.top();
	}
};

