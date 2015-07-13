/***********************
*Date:	2015.7.11
*Problems:	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*����:	����ı�����һ��ǰ������ɾ���ڵ�Ĺ��̣�Ҳ����forward_list�������ر�֮������������ǰ������
		forward_list����֮������ɾ���ڵ�Ĺ�������Ҫ����ǰһ���ڵ㣬��������ֻ�������ߣ�������Ҫһ��pre_f���浱ǰ�ڵ��ǰһ���ڵ�
		������Ʊ߽������Ĵ���Ƚ϶�Ҳ����Ϊû��һ���������ǰ������
*����	�߽������ҿ��Ƶ�̫���ˣ���Ȼ�Ѿ��������������ǿ��ǵĻ��ǲ�����ȫ
*Leetcode�� 12ms����ͦ���
***********************/
#pragma once
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class RemoveDuplicatesFromSortedListII
{
public:
	RemoveDuplicatesFromSortedListII();
	~RemoveDuplicatesFromSortedListII();
	ListNode* deleteDuplicates_Dwyer(ListNode* head) {
		if (head == NULL)	return head;
		ListNode *pre_f, *front = head;
		ListNode *back = head->next;
		bool flag = false;
		while (back != NULL){
			if (front->val == back->val){//�����ظ�
				flag = true;
				back = back->next;
			}
			else{
				if (flag == true){//�ҵ��ظ����֣�������λ�ã���preָ��back
					flag = false;
					if (front == head){//��һ�Ǵ�head��ʼ�ظ��ģ�������head
						head = back;
						pre_f = head;
						front = head;
						back = back->next;
						continue;
					}
					pre_f->next = back;
					front = back;
					back = back->next;
				}
				else{//�������
					pre_f = front;
					front = front->next;
					back = back->next;
				}
			}
		}
		if (flag == true)
			pre_f->next = NULL;
		if (flag == true && front == head)
			head = NULL;
		return head;
	}
};

