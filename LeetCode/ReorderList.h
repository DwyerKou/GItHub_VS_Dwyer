/*
Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*����
 */
#pragma once
#include "LeetCode.h"
class ReorderList
{
public:
	ReorderList();
	~ReorderList();
	/*
	һ��ʱ��n�ռ�n�����˼·
	����ac 64ms
	�󲿷ֶ������ʱ�䣬����������
	����һ�ַ�����ʵ��Ҳ�뵽�ˣ����Ǿ���д����ʱ�仹��n����ûʵʩ
	Ҳ����һ������һ��һ���ҵ��м�ģ�Ȼ����м�Ŀ�ʼ��תһ��
	Ȼ��������ƴ������
	*/
	void reorderList(ListNode* head) {
		if (!head) return;
		vector<ListNode*> v;
		while (head) {
			v.push_back(head);
			head = head->next;
		}
		auto front = v.begin();
		auto back = v.end() - 1;
		while (front < back) {
			(*front)->next = *back;
			++front;
			(*back)->next = *front;
			--back;
		}
		(*front)->next = nullptr;
	}
};

