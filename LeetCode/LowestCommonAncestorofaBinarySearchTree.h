/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��

_______6______
/              \
___2__          ___8__
/      \        /      \
0      _4       7       9
/  \
3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

* ����������һ���� �Լ����е������ڵ㣬�ҵ��������ڵ����С���ø��ڵ�
ע���������BST �����ܽ����
������ù���������϶����ԣ�1.��Ҫ�Լ�д�����㷨��2.�����˷ѵ���ʱ�䣬������ڵ㻹�����ӽڵ�

*/
#pragma once
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class LowestCommonAncestorofaBinarySearchTree
{
public:
	LowestCommonAncestorofaBinarySearchTree();
	~LowestCommonAncestorofaBinarySearchTree();

	//��������ǿ����˵ģ��������Լ���
	//��Ҫ���һ���û�ҵ����ɣ��ҵ��Ļ�ȴ�Ǻܼ�
	//��С���ڵ��ܱ�֤һ�������һ�����Ҳ࣬���������С�Ļ����϶�ͬʱ��������ͬʱ���Ҳ�
	//��ϸ����ȷʵ�ǰ�����ֱ�ӱȽϽڵ��ֵ�͸㶨�˰�
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left,p,q);
		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		return root;
	}
};

