/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following is not:
1
/ \
2   2
\   \
3    3

//��Ȼ���Եݹ飬���ó��Ե�����
ע��һ���£�����Ը��ڵ�Գƣ���������ÿ���ڵ㶼�Գ�
*/
#pragma once
#include "LeetCode.h"
class SymmetricTree
{
public:
	SymmetricTree();
	~SymmetricTree();
	//�������Ժ��õݹ�ȷʵ1���
	//4ms ���
	//�ȼ��鷳���ǵݹ�ôӸ������ҽڵ㿪ʼ�����ҵݹ麯�����µĽ��������ڵ��
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return valEqual(root->left, root->right);
	}
	bool valEqual(TreeNode* a, TreeNode* b){
		if (!a&&!b) return true;
		if (a&&b&&a->val == b->val)
			return valEqual(a->left, b->right) && valEqual(a->right, b->left);
		return false;
	}

	/*
	�����Ƿǵݹ�ķ���
	�Ҵ�������������ʵ��
	������4ms
	a�����Ƚ���ߵģ��ٽ��ұߵ�
	b�����Ƚ��ұߣ��ٽ����
	����Գƣ�a��b��ֵӦ��ʼ��һ��
	*/
	bool isSymmetric_Dwyer1(TreeNode* root) {
		if (!root) return true;
		deque<TreeNode*> a, b;
		a.push_back(root->left);
		b.push_back(root->right);
		while (!a.empty() && !b.empty()){
			if (a.front() && b.front()){
				if (a.front()->val != b.front()->val)
					return false;
				a.push_back(a.front()->left);
				a.push_back(a.front()->right);
				b.push_back(b.front()->right);
				b.push_back(b.front()->left);
				a.pop_front();
				b.pop_front();
				continue;
			}
			if (!a.front() && !b.front()){
				a.pop_front();
				b.pop_front();
				continue;
			}
			return false;
		}
		if (!a.empty() || !b.empty()) return false;
		return true;
	}
};

