/*
����ȫ�������ж��ٸ��ڵ�
*/
#pragma once
#include "LeetCode.h"
class CountCompleteTreeNodes
{
public:
	CountCompleteTreeNodes();
	~CountCompleteTreeNodes();
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		if (!root->left&&!root->right) return 1;
		int left = 0, right = 0;
		TreeNode *leftTree = root, *rightTree = root;
		while (leftTree) {
			left++;
			leftTree = leftTree->left;
		}
		while (rightTree) {
			right++;
			rightTree = rightTree->right;
		}
		if (left == right) return pow(2, left) - 1;
		else {
			//�ٷ�����������жϾ�������������ȫ������������ȫ
			int leftRight = 0;
			leftTree = root->left;
			while (leftTree) {
				leftRight++;
				leftTree = leftTree->right;
			}
			if (leftRight + 1 == left) //��������ȫ
				return pow(2, left - 1) + countNodes(root->right);
			else {//��������ȫ
				return pow(2, right - 1) + countNodes(root->left);
			}
		}
	}
};

