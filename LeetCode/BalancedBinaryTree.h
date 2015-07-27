#pragma once
#include "LeetCode.h"
class BalancedBinaryTree
{
public:
	BalancedBinaryTree();
	~BalancedBinaryTree();
	/*
		16ms
		��������ʱ��
		������һ���Ե����ϵķ���
		ʱ�临�Ӷ�ΪO(n)
	*/
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int a = height(root->left);
		int b = height(root->right);

		//ǰ����Ҫ���ǻ�Ҫ�ֱ��ж����������Ƿ�ƽ�⣡����������������
		return abs(a-b)<=1 &&isBalanced(root->right)&&isBalanced(root->left);
	}
	int height(TreeNode* root){
		if (!root) return 0;
		return max(height(root->left),height(root->right))+1;
	}
};

