/***********************
*Date:	2015.7.15
*Problems:	Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*����:	�ù���������ݹ�ķ�ʽ�����ƺý������������ˡ�12ms
*��Ŀ��	��������С���
*����	����ô���˹��ˣ�leetcode��ʼ˵��һ��ͨ����������һ����ͨ���ˣ������˷��˺ö�ʱ��
***********************/

#pragma once
#include <algorithm>
using namespace std;
class MinimumDepthofBinaryTree
{
public:
	MinimumDepthofBinaryTree();
	~MinimumDepthofBinaryTree();

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;

		if (root->left == nullptr&&root->right == nullptr) return 1;

		if (root->right == nullptr) return (minDepth(root->left) + 1);
		if (root->left == nullptr) return (minDepth(root->right) + 1);

		return (min(minDepth(root->left), minDepth(root->right)) + 1);
	}
};