/*
Sort a linked list using insertion sort.
*/
#pragma once
#include "LeetCode.h"
class InsertionSortList
{
public:
	InsertionSortList();
	~InsertionSortList();
	/*
	o(n*n)
	ʼ��Ҫ��һ��ָ��head��һ��ָ��������
	һ��ͨ�� 80ms
	��������ʱ��
	Ȼ�󿴵����˺ܿ죬�����õ�����ǲ���������
	*/
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* curr = head->next, *preCurr = head;
		while (curr) {
			ListNode* front = head;
			ListNode* preFront = front;
			while(front!=curr&&front->val<curr->val){
				preFront = front;
				front = front->next;
			}
			if (front == head) {//������ǰ��
				ListNode* temp = curr->next;
				curr->next = front;
				head = curr;
				curr = temp;
				preCurr->next = temp;
			}
			else if (front == curr) {//���ò��룬�Ѿ�����
				preCurr = curr;
				curr = curr->next;
			}
			else {//�м����
				ListNode* temp = curr->next;
				preFront->next = curr;
				curr->next = front;
				curr = temp;
				preCurr->next = temp;
			}
		}
		return head;
	}
};

