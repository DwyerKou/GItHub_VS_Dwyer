/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
#pragma once
#include "LeetCode.h"
class PartitionList
{
public:
	PartitionList();
	~PartitionList();
	/*
	greaterʼ���������ߣ�Ѱ��С��x�Ľڵ�
	lastLessָ���xС�����һ��
	firstGreat��Զָ���һ�����ڵ���x��
	8ms һ���
	*/
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) return head;
		ListNode* preHead = new ListNode(0), *greater = head, *lastLess = preHead;
		preHead->next = head;
		while (greater&&greater->val < x) { //���С��
			lastLess = greater;
			greater = greater->next;
		}
		ListNode* firstGreat = greater;
		if(!greater) return preHead->next;
		ListNode* preGreater = greater;
		greater = greater->next;
		while (greater) {
			if (greater->val < x) {
				lastLess->next = greater;
				preGreater->next = greater->next;
				greater->next = firstGreat;
				lastLess = lastLess->next;
				greater = preGreater->next;
				continue;
			}
			preGreater = greater;
			greater = greater->next;
		}
		return preHead->next;
	}
};

