/***********************
*Date:	2015.7.19
*Problems:	Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*����:	��һ�����������������ƺ���û��ʲô�ѵģ������õݹ��˼·
		��ÿһ���ڵ�����һ���
*����	
***********************/
#pragma once
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class InvertBinaryTree
{
public:
	InvertBinaryTree();
	~InvertBinaryTree();
	/*
	�ҵķ���
	�ݹ�ȷʵ�ܼ�
	4ms
	*/
	TreeNode* invertTree_Dwyer(TreeNode* root) {
		if (root == nullptr) return root;
		if (root->left == NULL && root->right == NULL) return root;
		std::swap(root->left, root->right);
		invertTree_Dwyer(root->left);
		invertTree_Dwyer(root->right);
		return root;
	}
};

