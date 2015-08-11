 /*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
 */
#pragma once
#include "LeetCode.h"
class CopyListwithRandomPointer
{
public:
	CopyListwithRandomPointer();
	~CopyListwithRandomPointer();
	/*
	�������ǽ�ָoffer������Ǹ����Ƹ�������
	��ÿ���ڵ�copyһ����������Ȼ���ڲ���random�ڵ�
	���Ͽ�
	����
	*/
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return head;
		//����һ��������
		RandomListNode *p = head;
		while (p) {
			RandomListNode *copy = new RandomListNode(p->label);
			copy->next = p->next;
			copy->random = p->random;
			p->next = copy;
			p = copy->next;
		}
		//��ʼ�޸�randomָ��
		p = head;
		while (p) {
			if (p->random)//ע�����randomʱ���޸ģ�����û���壬����
				p->next->random = p->random->next;
			p = p->next->next;
		}
		//�Ͽ�ԭ�еģ�ȡ���µ�
		//ע�⻹�����ƻ�ԭ�еĽṹ������Ҫ��ԭ�еĻ�ԭ��ȥ
		p = head;
		RandomListNode *newHead = p->next;
		while (p->next&&p->next->next) {
			RandomListNode *temp = p->next;
			p->next = p->next->next;
			temp->next = temp->next->next;
			p = p->next;
		}
		return newHead;
	}
};

