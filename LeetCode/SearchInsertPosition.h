/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 �� 2
[1,3,5,6], 2 �� 1
[1,3,5,6], 7 �� 4
[1,3,5,6], 0 �� 0
*/
#pragma once
#include "LeetCode.h"
class SearchInsertPosition
{
public:
	SearchInsertPosition();
	~SearchInsertPosition();
	//δ��̫��
	//Ҫ���ǵ��ϱ߽���±߽�
	//8ms���
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		if (nums[nums.size() - 1] < target) return nums.size();
		for (size_t i = 0;i < nums.size();++i) 
			if (nums[i] >= target) return i;
	}

	//�����ڴ������������в��ң��ֿ�ʼʹ�ö������
	int searchInsert_Binary(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		if (nums[nums.size() - 1] < target) return nums.size();
		if (nums[0] > target) return 0;
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			int mid = (j - i) / 2 + i;
			if (nums[mid] == target)
				return mid;
			if (nums[mid]>target)
				j = mid;
			else
				i = mid;
		}
		return i;
	}
};

