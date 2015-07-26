/*
	Given a binary tree, return the inorder traversal of its nodes' values.

	For example:
	Given binary tree {1,#,2,3},
	1
	\
	2
	/
	3
	return [1,3,2].

	Note: Recursive solution is trivial, could you do it iteratively?

	������������������ǿ����ö�ջʵ��
	����ָ���ǣ������Ȼ�󸸽ڵ�Ȼ���ұ�
	*/
#pragma once
#include "LeetCode.h"
class BinaryTreeInorderTraversal
{
public:
	BinaryTreeInorderTraversal();
	~BinaryTreeInorderTraversal();
	/*
		�ҵķ�����һ��ac��ˬ
		0ms
	*/
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		if (root == nullptr) return v;
		stack<TreeNode *> st;
		TreeNode * temp;
		st.push(root);
		while (!st.empty()){
			//����ͬʱΪ�� ȡֵ Ȼ��pop
			if (st.top()->left == nullptr&& st.top()->right == nullptr){
				v.push_back(st.top()->val);
				st.pop();
				continue;
			}
			//���󣬽���push���ж���ϵ
			else if (st.top()->left != nullptr){
				temp = st.top()->left;
				st.top()->left = nullptr;
				st.push(temp);
				continue;
			}
			//�������ң�����ȡtop��ֵ��Ȼ��pop��Ȼ���ҽڵ�push
			else if (st.top()->right != nullptr){
				v.push_back(st.top()->val);
				temp = st.top()->right;
				st.pop();
				st.push(temp);
				continue;
			}

		}

		return v;
	}
};

