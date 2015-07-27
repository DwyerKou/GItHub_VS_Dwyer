/*
	Sort a linked list in O(n log n) time using constant space complexity.
	��һ�������������Ҫ��ʱ����n logn �ռ��ǳ���
	��Ϊ������logn �����ζ��Ҫ��2�йأ�Ӧ���뵽�鲢����
	��Ҫ���ó����ռ�
	*/
#pragma once
#include "LeetCode.h"
class SortList
{
public:
	SortList();
	~SortList();
	/*
		������ҵ��÷����㷨ʵ�ֵ�
		ϵͳ�Դ���sort����������ʱ�临�Ӷ��Ҳ�֪��(�Ҳ�֪��sort�õ�ʲô����)���ռ临�Ӷ���o(n)
		leetcode 84ms ����
		�����ҽ�head == nullptr�����ˣ�head ���ʱ����ߵ���68ms����������������������������������������
		*/
	ListNode* sortList_Dwyer(ListNode* head) {
		vector < ListNode * > v;
		if (!head) return head;
		while (head){
			v.push_back(head);
			head = head->next;
		}
		sort(v.begin(), v.end(), [](const ListNode* a, const ListNode* b){return a->val < b->val; });
		for (size_t i = 0; i < v.size() - 1; ++i){
			v[i]->next = v[i + 1];
		}
		v[v.size() - 1]->next = nullptr;
		head = v[0];
		return head;
	}

	/*
		���� ��������Լ�д�Ĺ鲢�㷨
		62ms ��������ʱ��
		Ҫд�����ϸ�Ĵ����ע��headʲô�Ķ���ָ�룬Ȼ��ÿһ��ListNode���ڿռ��в���������������ȥ��ֻ�����е�next���ָ��Ĳ���
		���Բ�û�п����¿ռ�
	*/
	ListNode* sortList(ListNode* head) {
		if (!head || !(head->next)) return head;//����Ϊ1�Ϳյ�����
		ListNode* headkeep = head;
		int n=0;
		while (head){
			++n;
			head = head->next;
		}

		ListNode *mid = headkeep;
		for (size_t i = 0; i < n / 2-1; i++)
			mid = mid->next;
		ListNode *temp = mid->next;
		mid->next = nullptr;
		return Merge(sortList(headkeep), sortList(temp));//������ֱ�����Ȼ������ں�
	}

	ListNode* Merge(ListNode* first, ListNode* second) {
		if (!first || !second) return first ? first : second;
		//�����������¿���һ��head���������½���һ������ֻ�Ƕ���һ��ָ�����
		ListNode a(0);
		ListNode *head = &a;
		ListNode *re = head;//����Ƚ϶��ģ�д�����о���Ϊ�˳�ʼ��һ��head�����滹��ȥ��
		while (first && second){
			if (first->val < second->val){//˭С��˭
				head->next = first;
				first = first->next;
				head = head->next;
			}
			else{
				head->next = second;
				second = second->next;
				head = head->next;
			}
		}
		if (first) head->next = first;//��ʣ�µĲ��ֽ���
		if (second) head->next = second;
		return re->next;//ǰ�����һ��û�õ�ͷ����ȥ��
	}
};

