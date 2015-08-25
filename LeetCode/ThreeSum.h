/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
#pragma once
#include "LeetCode.h"
class ThreeSum
{
public:
	ThreeSum();
	~ThreeSum();
	/*
	������ȡ���е�һ�����֣�Ȼ����twoSum�Ǹ�����ȥ������
	�����ǰ��һ����Ļ������ҵ�����0�Ǹ�����û��Ҫ����ѭ����
	64ms
	�������������Ժ��������������һ��frontһ��back��һ���
	*/
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> re;
		if (nums.size() < 3) return re;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (size_t i = 0;i < n&&nums[i]<=0;++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int target = 0 - nums[i];
			set<int> s;
			int front = i + 1, back = n - 1;
			while (front < back) {
				if (nums[front] + nums[back] == target){
					re.push_back(vector<int>{nums[i], nums[front], nums[back]});
					front++;
					while (front < back && nums[front] == nums[front - 1]) front++;
					back--;
					while (front < back && nums[back] == nums[back + 1]) back--;
				}
				else if (nums[front] + nums[back] < target)
					front++;
				else
					back--;
			}
		}
		return re;
	}
};

