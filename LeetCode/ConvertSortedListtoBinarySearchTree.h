/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#pragma once
#include "LeetCode.h"
class ConvertSortedListtoBinarySearchTree
{
public:
	ConvertSortedListtoBinarySearchTree();
	~ConvertSortedListtoBinarySearchTree();
	/*
	��Ϊ�������������
	�����뵽�Ļ��Ƕ��ַ�
	��ConvertSortedArraytoBinarySearchTree��ʵ��һ������
	һ��� 28ms ����ʱ��
	*/
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return new TreeNode(head->val);
		int n = 0;
		ListNode *head_backup = head;
		while (head) {
			++n;
			head = head->next;
		}
		head = head_backup;
		int mid = n / 2;
		for (int i = 0;i < mid - 1;++i)
			head = head->next;
		TreeNode* root = new TreeNode(head->next->val);
		root->right = sortedListToBST(head->next->next);
		head->next = NULL;
		root->left = sortedListToBST(head_backup);
		return root;
	}

	/*
	����ķ����������һ����n
	��ʵ������ָ��һ�����������ߣ�һ��һ��һ���߼���
	����28ms
	*/
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return new TreeNode(head->val);
		ListNode *slow = head, *fast = head,*pre= head;
		while (fast&&fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		root->right = sortedListToBST(slow->next);
		pre->next = NULL;
		root->left = sortedListToBST(head);
		return root;
	}
};

