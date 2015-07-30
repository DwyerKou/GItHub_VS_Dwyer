/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
#pragma once
#include "LeetCode.h"
class LinkedListCycle
{
public:
	LinkedListCycle();
	~LinkedListCycle();
	/*
	12ms һ��� ����
	˼�룬ÿ�α������ýڵ㶼����ָ���׽ڵ�
	������������߻����׽ڵ㣬˵������cycle
	�����������ܸߵ��������Ҿ��ò��ã�������һ��fastÿ����������һ��slowÿ����һ��
	������ڻ��������غϵ�ʱ��
	���������ܱȽϺ�ʱ��
	*/
	bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode *headFlag = head;
		head = head->next;
		while (head&&head != headFlag){
			ListNode *temp = head->next;
			head->next = headFlag;
			head = temp;
		}
		if (head) return true;
		return false;
	}
};

