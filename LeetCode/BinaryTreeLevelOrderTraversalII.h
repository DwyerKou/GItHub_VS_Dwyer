/*
	Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
�����ǲ�α���������
�����Ҫ������
˳�����ˣ�ֱ�Ӱ�˳�ŵ����Ŵ�һ��϶���
*/
#pragma once
#include "LeetCode.h"
class BinaryTreeLevelOrderTraversalII
{
public:
	BinaryTreeLevelOrderTraversalII();
	~BinaryTreeLevelOrderTraversalII();
	/*
		������ķ���
		Ȼ�����reverse����
		������4ms
	*/
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		//һ�µĲ�������ֱ�Ӵ�˳�ŵ�����ճ������
		vector<vector<int>> vv;
		if (!root) return vv;
		deque<TreeNode*> q;
		vector<int> v;

		q.push_back(root);
		int count = 1;
		int nextCount = 0;
		while (!q.empty()){
			v.push_back(q.front()->val);
			if (q.front()->left) {
				q.push_back(q.front()->left);
				++nextCount;
			}
			if (q.front()->right) {
				q.push_back(q.front()->right);
				++nextCount;
			}
			q.pop_front();
			if (--count == 0){
				vv.push_back(v);
				v.clear();
				count = nextCount;
				nextCount = 0;
			}
		}
		//���￪ʼ�ǰ�˳�������������
		reverse(vv.begin(),vv.end());
		return vv;
	}
};

