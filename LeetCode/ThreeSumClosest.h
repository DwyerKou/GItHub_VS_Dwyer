/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#pragma once
#include "LeetCode.h"
class ThreeSumClosest
{
public:
	ThreeSumClosest();
	~ThreeSumClosest();
	/*
		�ɶ�������Щ��������������������Ч����ߵ���
		12ms ���
	*/
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return -1;
		int re = INT_MAX, n = nums.size();//re�������Ŀǰ��������target�ľ���
		sort(nums.begin(), nums.end());
		for (size_t i = 0;i < n - 2;i++) {
			int targetTwo = target - nums[i], front = i + 1, back = n - 1;
			int reTemp = INT_MAX;//reTemp�������Ŀǰ��������targetTwo�ľ���
			while (front < back) {
				int sum = nums[front] + nums[back];
				if (sum == targetTwo) return target;
				else if (sum < targetTwo) front++;
				else back--;
				if (abs(sum - targetTwo) < abs(reTemp)) reTemp = sum - targetTwo;
			}
			if (abs(target - (reTemp + targetTwo + nums[i])) < abs(re))
				re = reTemp + targetTwo + nums[i] - target;
		}
		return re + target;
	}
};

