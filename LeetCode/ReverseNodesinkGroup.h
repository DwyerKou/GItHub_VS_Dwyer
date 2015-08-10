/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
#pragma once
#include "LeetCode.h"
class ReverseNodesinkGroup
{
public:
	/*
	�о��������ǿ��᲻������ʱ�临�ӶȾ���nk�ˣ�û���㵽lgn
	*/
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k < 2) return head;
		ListNode* pre = head, *temp, *realHead=head;
		head = head->next;
		bool theFirstHead = true;
		ListNode* prepre = pre,*preprepre;
		while (head) {
			int i = k - 1;
			ListNode* headBackupThisCycle = pre;
			while (i&&head) {
				temp = head->next;
				head->next = pre;
				pre = head;
				head = temp;
				i--;
			}
			if (i == 0) {//�պ÷���������õ�һ���ڵ�ָ����һ���ڵ�����ˣ���һ��Ϊ��Ҳ����
				if (theFirstHead) {
					realHead = pre;
					theFirstHead = false;
				}
				if (head) {// ���head��ûָ����
					//����һ�����һ��ָ����һ�ε�һ��
					preprepre = prepre;
					prepre->next = head;
					prepre = head;
					//��pre��head����Ϊ��һ�εķ�ת��׼��
					pre = head;
					head = head->next;
					headBackupThisCycle->next = pre;
				}
				else {
					headBackupThisCycle->next = nullptr;
					preprepre->next = pre;
				}
			}
			else {//˵��kԽ����Ӧ���ٰ����һ�εĸ�������
				ListNode* a = pre;
				head = pre->next;
				while (i++!=k-1) {
					temp = head->next;
					head->next = pre;
					pre = head;
					head = temp;
				}
				a->next = nullptr;
				break;
			}
		}
		return realHead;
	}
};

