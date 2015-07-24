/*Reverse a singly linked list.
	��������
*/
#pragma once
#include <deque>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class ReverseLinkedList
{
public:
	ReverseLinkedList();
	~ReverseLinkedList();
	/*
	12 ms   �ҵ�
	���ڵ�ȫ���浽queue�У�Ȼ�������޸�ÿ���ڵ��next����
	*/
	ListNode* reverseList_Dwyer(ListNode* head) {
		if (head == nullptr || head->next == NULL) return head;
		deque<ListNode*> q;
		while (head != nullptr){
			q.push_back(head);
			head = head->next;
		}
		auto b = q.begin();
		(*b)->next = nullptr;
		++b;
		while (b != q.end()){
			(*b)->next = *(b - 1);
			++b;
		}
		return q.back();
	}

	/*
	���˵� ��ǰ����һ��һ���޸�ÿһ���ڵ��next��һ��Ҳ���ѣ�Ϊʲô�������뵽��ȴ�Ǵ����һ���ڵ㿪ʼ�޸�
	��
	8ms
	*/
	ListNode *reverseList(ListNode *head) {
		ListNode *pre = nullptr;
		while (head != nullptr){
			ListNode *next = head->next;//��head��ԭ��next�ȴ�����
			head->next = pre;//�޸�head��nextָ��pre
			pre = head;//pre����Ӧ����head��
			head = next;//head����һ���ڵ�
		}
		return pre;//ע������Ҫ����pre��������head
	}
};

