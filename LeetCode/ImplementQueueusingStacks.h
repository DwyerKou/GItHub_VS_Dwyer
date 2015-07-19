/*
��stackʵ��queue
������������Ժ�������
�������������Ǹ�Queue��Ȼ����һ������queue�����queue��push,pop��peek��empty�ķ�����������Щ������ʱ���ܱ�֤�������
ÿ����queue��ĩ����ֵ������input���Ԫ��
ÿ����Ҫȡqueueͷֵ���Ͱ�input�����ȫ������output�м���
ÿ����Ҫȥͷ���Ͱ�input�����ȫ������output�У�Ȼ��ȥ��output������
input+output������queue��ֵ��
���еĻ�ֻ��β������ͷ����
*/
#pragma once
#include <stack>
using namespace std;
class ImplementQueueusingStacks
{
	//������Ⱑ �� ���input�����棬�൱��queue�������
	stack<int> input, output;

public:
	ImplementQueueusingStacks();
	~ImplementQueueusingStacks();

	// Push element x to the back of queue.
	void push(int x) {
		input.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (output.empty())
			while (input.size())
				output.push(input.top()), input.pop();
		output.pop();
	}

	// Get the front element.
	int peek(void) {
		if (output.empty())
			while (input.size())
				output.push(input.top()), input.pop();
		return output.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return input.empty() && output.empty();
	}
};

