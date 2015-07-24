/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
�K
c1 �� c2 �� c3
�J
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#pragma once
#include "LeetCode.h"
class IntersectionofTwoLinkedLists
{
public:
	IntersectionofTwoLinkedLists();
	~IntersectionofTwoLinkedLists();
	/*
		�ҵ�52ms
		����˼·��������������
		Ȼ���ýϳ����Ǹ��Ѷ�������ǲ�����ǰ����
		Ȼ����������ͬʱ��ʼ������
	*/
	ListNode *getIntersectionNode_Dwyer(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		size_t lengthA = 0, lengthB = 0;
		ListNode * ptA = headA;
		ListNode * ptB = headB;
		ListNode * re = nullptr;
		while (ptA != nullptr){
			lengthA++;
			ptA = ptA->next;
		}
		while (ptB != nullptr){
			lengthB++;
			ptB = ptB->next;
		}
		ptA = headA;
		ptB = headB;
		if (lengthA > lengthB){
			for (size_t i = 0; i < lengthA - lengthB; i++){
				ptA = ptA->next;
			}
		}
		if (lengthA < lengthB){
			for (size_t i = 0; i < lengthB - lengthA; i++){
				ptB = ptB->next;
			}
		}
		bool flag = false;
		for (size_t i = 0; i < (lengthA>lengthB?lengthB:lengthA); i++){
			/*if (ptA->val == ptB->val && !flag){
				re = ptA;
				flag = true;
			}
			if (ptA->val != ptB->val && flag){
				re = nullptr;
				flag = false;
			}*/
			//���ϵ���������
			if (ptA==ptB){
				return ptA;
			}
			ptA = ptA->next;
			ptB = ptB->next;
		}
		return re;
	}

	/*
		���Ǳ��˵��뷨�����Լ��ǳ���û���
		ֱ������ָ�룬��ָ��ֻҪ��Ⱦͷ���
		������Ȳ�ͬ��if (p1 == NULL) p1 = headB;
			if (p2 == NULL) p2 = headA;�͸պ��ܵ������Ȳ��λ�ú�ոպ�λ��ͬ��

		��������֮�������ߵ�ͷ��һ����ָ��ͬ��
	*/
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *p1 = headA;
		ListNode *p2 = headB;

		if (p1 == NULL || p2 == NULL) return NULL;

		while (p1 != NULL && p2 != NULL && p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;

			//
			// Any time they collide or reach end together without colliding 
			// then return any one of the pointers.
			//
			if (p1 == p2) return p1; //���ﲻ���ж�ֵ��ȶ���ֱ���ж�����ָ���Ƿ���ͬ

			//
			// If one of them reaches the end earlier then reuse it 
			// by moving it to the beginning of other list.
			// Once both of them go through reassigning, 
			// they will be equidistant from the collision point.
			//
			if (p1 == NULL) p1 = headB; //�����ǹؼ��������ߵ�ͷ�Ժ�һ�¾�ͬ����
			if (p2 == NULL) p2 = headA;
		}

		return p1;
	}
};

