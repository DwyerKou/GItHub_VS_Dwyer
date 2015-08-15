/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
1            <---
/   \
2     3         <---
\     \
5     4       <---
You should return [1, 3, 4].
*/
#pragma once
#include "LeetCode.h"
class BinaryTreeRightSideView
{
public:
	BinaryTreeRightSideView();
	~BinaryTreeRightSideView();
	/*
	������վ���ұߣ�һ��һ�㿴
	������ڵ�����ڵ㣬���㿴��������ߵ�
	û�еĻ��㿴�������ұߵ�
	Ҫȥ��һ��Ļ���Ҫ����a��b��c��c��Ҷ�ӣ���b���ǣ���ô��һ����b����һ��
	�����㻹��Ҫ�������ڵ㣬��ĳ�����ݽṹ
	���Կ��ǳɲ�α�������ô����Ҫ�õ����У�ÿ�ο�������ÿ������ұߣ�ʱ�临�ӶȾ���n

	�㶨 һ��� 4ms �����������ʱ�� ��Ҵ�Ŷ���ô����
	*/
	vector<int> rightSideView(TreeNode* root) {
		vector<int> v;
		deque<TreeNode*> q;
		int countEveryLevel=1;
		if (!root) return v;
		q.push_back(root);
		while (!q.empty()) {
			if (q.front()->left) q.push_back(q.front()->left);
			if (q.front()->right) q.push_back(q.front()->right);
			if (countEveryLevel == 1) {
				v.push_back(q.front()->val);
				q.pop_front();
				countEveryLevel = q.size();
			}
			else {
				q.pop_front();
				countEveryLevel--;
			}
		}
		return v;
	}
};

