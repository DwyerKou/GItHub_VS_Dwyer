/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 �� k �� BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).

�ұ����뵽�ķ���������������Ʊغ�����
������������ŵ�ʱ����lgn
���Կ�����ô������һֱ�����ҵ���С��
Ȼ��k-- ����Ѱ�Ҹ��ڵ�Ȼ�����ҽڵ�
��������������Ҫһ���ṹ�������游�ڵ���а�
*/
#pragma once
#include "LeetCode.h"
class KthSmallestElementinaBST
{
public:
	KthSmallestElementinaBST();
	~KthSmallestElementinaBST();
	/*
	24ms ����Ҳ����
	�������������õݹ�ķ���
	*/
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		st.push(root);
		while (st.top()->left != NULL)
			st.push(st.top()->left);
		while (k--!=1) {
			if (st.top()->right) {
				TreeNode* temp = st.top();
				st.pop();
				st.push(temp->right);
				while (st.top()->left)
					st.push(st.top()->left);
			}
			else
				st.pop();
		}
		return st.top()->val;
	}
};

