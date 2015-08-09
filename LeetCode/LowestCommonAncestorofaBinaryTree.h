/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that
has both v and w as descendants (where we allow a node to be a descendant of itself).��

_______3______
/              \
___5__          ___1__
/      \        /      \
6      _2       0       8
/  \
7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is 
LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/
#pragma once
#include "LeetCode.h"
class LowestCommonAncestorofaBinaryTree
{
public:
	LowestCommonAncestorofaBinaryTree();
	~LowestCommonAncestorofaBinaryTree();
	/*
	���˺ܾ������뵽����
	ע����ֿ���
	��һ��vector��α���֮
	�������ҵ����ɵ�һ���ҵ�����ǰһ��һ���жϺ͸���
	����нڵ�ֻ��p�ĸ��ڵ㣬��p�滻Ϊ����ڵ�
	֪���ҵ�ͬʱ��p��q���ڵ�Ľڵ�
	����֮
	��������һ��㶨��������������������24ms���ģ���!!!!!!!!!
	�����Ϊ��ǰ��ֹ�ˣ��ȵݹ�ʲô�Ķ��죡��������������������
	*/
	TreeNode* lowestCommonAncestor_Dwyer1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return root;
		if (!p||!q) return NULL;
		if (p == root || q == root) return root;
		if (p == q) return p;
		vector<TreeNode*> v;
		int pos_p = 0,pos_q = 0;
		v.push_back(root);
		int i = 0;
		while(!pos_p||!pos_q){//����������Ϊ0�ǣ�˵��vector��û��Ҫ������������
			if (v[i] == p)
				pos_p = i;
			if (v[i] == q)
				pos_q = i;
			if (v[i]->left)
				v.push_back(v[i]->left);
			if (v[i]->right)
				v.push_back(v[i]->right);
			++i;
		}
		//�������p��q��v�е�λ�ö��Ѿ��ҵ�����������һ��һ��һ����ǰ��ע��p��q�����Ǹ��ӹ�ϵ����
		int index = max(pos_p, pos_q)-1;
		while (index >= 0) {
			if ((v[index]->left == v[pos_p] && v[index]->right == v[pos_q]) 
				|| (v[index]->left == v[pos_q] && v[index]->right == v[pos_p])
				||(v[index]==v[pos_q]&&(v[index]->left == v[pos_p] || v[index]->right == v[pos_p]))
				|| (v[index] == v[pos_p] && (v[index]->left == v[pos_q] || v[index]->right == v[pos_q])))
				return v[index];
			else if (v[index]->left == v[pos_p] || v[index]->right == v[pos_p])
				pos_p = index;
			else if (v[index]->left == v[pos_q] || v[index]->right == v[pos_q])
				pos_q = index;
			index--;
		}
		return root;
	}


	/*
	�ݰ������õݹ���Ժܼ򵥵İ���������������Ϊëû�뵽��������������
	24ms
	�����ȷǵݹ������ ��������������������
	*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return !right ? left : !left ? right : root;
	}
};

