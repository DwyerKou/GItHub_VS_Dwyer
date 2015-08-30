/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/
#pragma once
#include "LeetCode.h"
class SumRoottoLeafNumbers
{
public:
	SumRoottoLeafNumbers();
	~SumRoottoLeafNumbers();
	/*
	4ms
	�Լ���д�˸�������ǰ���ֵ����ͳ�Ƴ�����
	Ȼ��ݹ�������
	*/
	int sumNumbers(TreeNode* root) {
		int re = 0;
		sumNumbers(root,0,re);
		return re;
	}
	void sumNumbers(TreeNode *root, int num, int &re) {
		if (!root)	return;
		int temp = num * 10 + root->val;
		if (!root->left&&!root->right) {
			re += temp;
			return;
		}
		sumNumbers(root->left, temp, re);
		sumNumbers(root->right, temp, re);
	}
};

