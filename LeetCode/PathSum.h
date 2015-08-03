/***********************
*Date:	2015.7.19
*Problems:	Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*����:	���������һ������22���ߵ���Ҷ��ȴ������22���򷵻ظ��ڵ㣬�������ڵ���Ҳ�ڵ�
��Ҫ���ǵ�sum�п����Ǹ��������Բ����ϸ��մ���22������ÿһ�ζ���֤�ߵ���Ҷ�ӽڵ㣬�жϵ��ڻ��߲����ڲ���
Ҷ�ӽڵ�����������Ҷ��Ӷ��ǿ�

*��Ŀ��
*����
***********************/
#pragma once
#include "LeetCode.h"
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class PathSum
{
public:
	PathSum();
	~PathSum();
	/********************
	*����:�������д�ķ��������õݹ��˼·���������
	*ʱ�临�Ӷȣ�����Ҫ����ÿ���ڵ㣬Ҳ����o(n)
	*LeetCodeЧ��:12s
	*����:һ��ͨ����˼·����
	********************/
	bool hasPathSum_Dwyer(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		if (root->left == NULL && root->right == NULL && root->val == sum) return true;
		if (hasPathSum_Dwyer(root->left, sum - root->val) || hasPathSum_Dwyer(root->right, sum - root->val)) return true;
		return false;
	}
};

