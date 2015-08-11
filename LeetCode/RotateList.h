/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
#pragma once
#include "LeetCode.h"
class RotateList
{
public:
	RotateList();
	~RotateList();
	/*
	��ȷ��k�ǲ��Ǵ���n�����������n����
	����n�Ļ���Ҫ��ǰ��һ��Ȼ��ȡģ
	�ðɷ��ˣ���ȻҪ����k���ڵ���n�����
	12ms ����ʱ��
	*/
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next || k == 0) return head;
		ListNode* headbackup = head, *slow = head, *fast = head;
		int n = 0;
		while (head) {
			++n;
			head = head->next;
		}
		k = k%n;
		if (k == 0) return headbackup;
		//fast ����k��
		for (int i = 0;i < k;i++)
			fast = fast->next;
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		ListNode *newhead = slow->next;
		slow->next = nullptr;
		fast->next = headbackup;
		return newhead;
	}
};

