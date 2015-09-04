/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
#pragma once
#include "LeetCode.h"
class SubsetsII
{
public:
	SubsetsII();
	~SubsetsII();
	/*
		���˶��ظ�Ԫ�صĴ�����ô���Կ��ǰѽ���ȴ��һ��set�У�Ȼ����תΪvector
		16ms
	*/
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> re;
		set<vector<int>> reSet;
		sort(nums.begin(), nums.end());
		vector<int> nullVec;
		reSet.insert(nullVec);
		for (int i = 0;i < nums.size();i++) {
			set<vector<int>> reSetCopy = reSet;//��һ�����ܻ�ܺķѿռ�
			for (auto it = reSetCopy.begin();it!= reSetCopy.end();it++) {
				vector<int> temp = *it;
				temp.push_back(nums[i]);
				reSet.insert(temp);
			}
		}
		re.assign(reSet.begin(), reSet.end());
		return re;
	}
};

