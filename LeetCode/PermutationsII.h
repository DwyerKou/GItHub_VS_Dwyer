/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
#pragma once
#include "LeetCode.h"
class PermutationsII
{
public:
	PermutationsII();
	~PermutationsII();
	/*
		�ݹ��ϻ���
			��ÿһ��Ԫ����һ����Ԫ�أ�Ȼ��ݹ����ʣ�µ�����

		һ��Ҫע�⣬ֻҪ���Ԫ�غ�ĳ��ֵ�����ˣ���ô�Ժ��ٳ������ֵ�Ͳ�����
		����������һ��set����ÿ�εݹ��ù���ֵ
		36ms
		����ac�˰�
	*/
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> re;
		if (nums.empty()) return re;
		//��ΪҪ���ϵ�swap��Ԫ�ط�����λ�ã�������ʵnums�����Ϳ�����path��û��Ҫ�����µ�path
		permuteUnique(re, nums, 0);
		return re;
	}

	void permuteUnique(vector<vector<int>> &re, vector<int>& nums,int index) {
		if (index == nums.size()) {
			re.push_back(nums);
			return;
		}
		set<int> swaped;//!!!!!!��������Ҫ��ʹ��
		for (int i = index;i < nums.size();i++) {
			if (swaped.find(nums[i]) != swaped.end()) continue;//��ֹ�����������ٴα��滻
			swap(nums[i], nums[index]);
			permuteUnique(re, nums, index+1);
			swap(nums[i], nums[index]);
			swaped.insert(nums[i]);
		}
	}
};

