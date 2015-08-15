/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#pragma once
#include "LeetCode.h"
class AddTwoNumbers
{
public:
	AddTwoNumbers();
	~AddTwoNumbers();
	/*
	ֱ����ǰ����� Ȼ�󷵻ؾ�����
	44ms
	���´����൱����
	*/
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int flag = 0;//��λ��־
		ListNode *newHead = new ListNode(0), *headbackup = newHead;
		while (l1 || l2 || flag) {//������flag�������l1,l2�����ˣ�����flag����1�����while���ܴ���յ����
			int n = l1 ? l1->val : 0; +l2 ? l2->val : 0; +flag;
			flag = n / 10;
			ListNode* newNode = new ListNode(n % 10);
			newHead->next = newNode;
			newHead = newHead->next;
			l1 = (l1 ? l1->next : nullptr);
			l2 = (l2 ? l2->next : nullptr);
		}
		return headbackup->next;
	}
};

