/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2   5
/ \   \
3   4   6
The flattened tree should look like:
1
\
2
\
3
\
4
\
5
\
6
*/
#pragma once
#include "LeetCode.h"
class FlattenBinaryTreetoLinkedList
{
public:
	FlattenBinaryTreetoLinkedList();
	~FlattenBinaryTreetoLinkedList();
	/*
	Ҫ�޸���
	����ԭ����ǰ�����˵����stack
	easy

	Ȼ����stack����������
	���Ǿ͸��õݹ���
	*/
	void flatten(TreeNode* root) {
		if (!root || (!(root->left) && !(root->right))) return;
		flatten(root->left);
		flatten(root->right);
		TreeNode*left = root->left, *leftBackup = left;
		if (left) {
			while (left->right)
				left = left->right;
			left->right = root->right;
			root->left = nullptr;
			root->right = leftBackup;
		}
	}
};

