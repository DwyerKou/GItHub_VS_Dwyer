/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
����һ����������������
*/
#pragma once
#include "LeetCode.h"
class BinaryTreePreorderTraversal
{
public:
	BinaryTreePreorderTraversal();
	~BinaryTreePreorderTraversal();
	/*
	����ʹ�õݹ�ķ���
	��ʹ�õ����ķ���
	*/
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		if (root == nullptr) return v;
		st.push(root);
		v.push_back(root->val);
		while (!st.empty()){
			if (st.top()->left == nullptr && st.top()->right == nullptr){
				st.pop();
			}
			if (st.top()->left != nullptr){
				st.push(st.top()->left);
				v.push_back(st.top()->left->val);
				st.top()->left = nullptr;
				continue;
			}
			if (st.top()->right != nullptr){
				st.push(st.top()->right);
				v.push_back(st.top()->right->val);
				st.top()->right = nullptr;
				continue;
			}
		}
		return v;
	}
};