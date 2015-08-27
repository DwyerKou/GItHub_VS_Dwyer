/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
#pragma once
#include "LeetCode.h"
class FindMinimuminRotatedSortedArray
{
public:
	FindMinimuminRotatedSortedArray();
	~FindMinimuminRotatedSortedArray();
	/*
	4ms ˼·���Ƕ��ֲ���
	*/
	int findMin(vector<int>& nums) {
		if (nums.empty()) return -1;
		if (nums.size() == 1) return nums[0];
		int f = 0, b = nums.size() - 1;
		while (f + 1 < b) {
			int mid = (f + b) / 2;
			//���µĴ���Ҫע�⣬ÿ���ҵ��м��Ԫ���������һ��Ԫ�ؽ��бȽ�
			if (nums[mid] < nums[b])
				b = mid;
			else
				f = mid;

			//���ÿ���ҵ�Ԫ������ǰ��Ԫ�ؽ��бȼۣ����Ѿ����������¾�bug��
		}
		return nums[f] < nums[b] ? nums[f] : nums[b];
	}
};

