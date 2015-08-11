/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 �� m �� n �� length of list.
*/
#pragma once
#include "LeetCode.h"
class ReverseLinkedListII
{
public:
	ReverseLinkedListII();
	~ReverseLinkedListII();
	/*
	front ����ǲ��÷�ת�����һ��Ԫ��
	back�����һ��Ԫ��
	�㶨4ms ʱ�仹����
	*/
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || m == n) return head;
		ListNode* preHead = new ListNode(0);
		preHead->next = head;
		ListNode *front = preHead, *back,*temp, *pre;
		for (size_t i = 1;i <= n;++i) {
			if (i < m) {
				front = head;
				head = head->next;
			}
			else if (i == m) {
				pre = head;
				head = head->next;
				back = pre;
			}
			else {
				temp = head->next;
				head->next = pre;
				pre = head;
				head = temp;
			}
		}
		front->next = pre;//��frontָ��ת��ĵ�һ��
		back->next = head;//�÷�ת������һ��ָ����һ��
		return preHead->next;
	}
};

