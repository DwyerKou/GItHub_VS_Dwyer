/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
1
/  \
2    3
/ \  / \
4  5  6  7
After calling your function, the tree should look like:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
Show Tags
Show Similar Problems

*/
#pragma once
#include "LeetCode.h"
class PopulatingNextRightPointersinEachNode
{
public:
	PopulatingNextRightPointersinEachNode();
	~PopulatingNextRightPointersinEachNode();
	/*
	�����ڲ�α���������
	���Կ����ö���
	һ���
	28ms
	*/
	void connect_Dwyer(TreeLinkNode *root) {
		if (!root) return;
		deque<TreeLinkNode*> q;
		q.push_back(root);
		int count = 1; //count����ͳ�Ʊ���һ����ʣ���ٸ��ڵ�
		int i = 0;//i�ǲ���
		while (!q.empty()){
			if (q.front()->left){
				q.push_back(q.front()->left);
				q.push_back(q.front()->right);
			}
			TreeLinkNode* temp = q.front();
			q.pop_front();
			if (--count == 0){
				++i;
				count = pow(2, i);
				temp->next = nullptr;
			}
			else
				temp->next = q.front();
		}
	}

	/*
	���˵ķ���
	�����Ŷ�����ʵ
	���ѭ���������£�ÿ���ó�ʼ�ڵ�Ϊ����������
	�ڲ�ѭ���������ҡ�
	*/
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		TreeLinkNode *pre = root;
		TreeLinkNode *cur = NULL;
		while (pre->left) {//���
			cur = pre;
			while (cur) {//�ڲ㣬ÿ���ڲ�ѭ������������һ���next
				cur->left->next = cur->right;
				if (cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;//���
		}
	}
};

