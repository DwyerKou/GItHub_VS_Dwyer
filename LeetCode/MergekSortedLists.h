/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#pragma once
#include "LeetCode.h"
class MergekSortedLists
{
public:
	/*
	�ҵķ���
	���������С�ѣ����Խ�ʱ�临�ӶȽ���nlgk���ռ�k
	�����Ҿ�Ȼû��ʹ�öѣ�����vector���min_element������ÿ�ζ�Ҫ����С�ģ����Ӷ�Ӧ����nk
	Ȼ���÷�����ʱ�ˣ���
	*/
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		ListNode* head = new ListNode(0);
		ListNode* prehead = head;
		int k = lists.size();
		vector<ListNode*> v;
		for (size_t i = 0;i < k;++i)
			if (lists[i])
				v.push_back(lists[i]);
		while (!v.empty()) {
			auto it = min_element(v.begin(), v.end(), [](ListNode* a, ListNode* b) { return a->val < b->val; });
			head->next = *it;
			head = head->next;
			if ((*it)->next)
				*it = (*it)->next;
			else
				v.erase(it);
		}
		return prehead->next;
	}

	/*
	���ո�ȥ������
	���������ķ�������ʹ�öѣ�Ȼ���Ҿ�ȻӦΪ����д�ȽϹ���ȼ۸��ӣ����ò����������ģ���Ȼ���������ַ���������
	��ֱ�����Լ�
	�ٴκú�д�ɣ���˳��ѧһ��д�ѵıȽϹ���Ҳ����set
	420ms
	����ͨ��
	�������������һ��Ҫѧ��set��ʹ�ã����Ǹ��ر�Ľ�ɫ���ܽ�ʱ�临�ӶȽ���lgn
	*/
	ListNode* mergeKLists_Dwyer(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		ListNode* head = new ListNode(0);
		ListNode* prehead = head;
		multiset<ListNode*, com> s;
		auto it = lists.begin();
		while (it != lists.end()) {
			if (*it)
				s.insert(*it);
			++it;
		}
		while (!s.empty()) {
			auto b = s.begin();
			head->next = *b;
			head = head->next;
			if ((*b)->next) 
				s.insert((*b)->next);
			s.erase(b);
		}
		return prehead->next;
	}
	struct com {
		bool operator() (ListNode *a, ListNode *b) {
			return a->val < b->val;
		}
	};
};