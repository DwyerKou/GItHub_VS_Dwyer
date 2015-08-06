/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#pragma once
#include "LeetCode.h"
class ConvertSortedArraytoBinarySearchTree
{
public:
	ConvertSortedArraytoBinarySearchTree();
	~ConvertSortedArraytoBinarySearchTree();
	/*
	�߶�Ҫƽ�⣬Ҳ�������Ҹ߶Ȳ����Ϊ1
	��Ϊ�Ѿ���������ֱ�Ӷ���
	20ms
	����ʱ��
	*/
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return NULL;
		return sortedArrayToBST(nums, 0, nums.size()-1);
	}
	TreeNode* sortedArrayToBST(vector<int>& nums, int front, int back) {
		if (front > back) return NULL;
		int mid = (front + back) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		if (front == back) return root;
		TreeNode* root_back = root;
		root->left = sortedArrayToBST(nums, front, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, back);
		return root_back;
	}
};

