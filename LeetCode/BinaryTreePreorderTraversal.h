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
	��һ��stackʵ��Ҳ����
	��Ҫע�����ÿ��Ҫ��һ���ڵ�push��ջ������Ҫ�����ڵ������ڵ����ϵն��
	leetcode 4ms
	*/
	vector<int> preorderTraversal_Dwyer(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* temp;
		if (root == nullptr) return v;
		st.push(root);
		v.push_back(root->val);
		while (!st.empty()){
			if (st.top()->left == nullptr && st.top()->right == nullptr){
				st.pop();
				continue;
			}
			if (st.top()->left != nullptr){
				temp = st.top()->left;
				st.top()->left = nullptr;
				st.push(temp);
				v.push_back(temp->val);
				continue;
			}
			if (st.top()->right != nullptr){
				temp = st.top()->right;
				st.top()->right = nullptr;
				st.push(temp);
				v.push_back(temp->val);
				continue;
			}
		}
		return v;
	}

	/*
		���˵ķ���  ���ֻ��Ҫ0ms
		����˼�룺������˵push right��Ȼ��push left
				�´�ѭ��ȡ���ÿ�ΰ�����ڵ��ٸ�pop������Ȼ��ȡֵ��Ȼ��������ȡ������ֵ���ұ����
				��Ȼ����ȡ����left��ֵ��Ȼ����right��ֵ��
				�����˼ҶԶ�ջ��Ӧ�ñ��ҵ��Ǹ�Ҫ��
				��Ȼͬ�Ƕ�ջ����ȴ�ǲ�һ����˼·
	*/
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodeStack;
		vector<int> result;
		//base case
		if (root == NULL)
			return result;
		nodeStack.push(root);
		while (!nodeStack.empty())
		{
			TreeNode* node = nodeStack.top();
			result.push_back(node->val);
			nodeStack.pop();
			if (node->right)
				nodeStack.push(node->right);
			if (node->left)
				nodeStack.push(node->left);
		}
		return result;
	}
};