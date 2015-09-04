/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
Hide Tags Array Backtracking Bit Manipulation
*/
#pragma once
#include "LeetCode.h"
class Subsets
{
public:
	Subsets();
	~Subsets();
	/*
		ע�������Ŀû���ظ�Ԫ�أ����ظ�Ԫ�صĻ���һ�µ�д���Ͳ����ˣ�����1,3,3�����ܳ���������3�������Ρ�1,3��
		�������һ�ֽⷨ���Ǳ�����10��Ԫ�أ���ô����һ�����ִ�0��2��10�η�-1��Ȼ��������ֶ�Ӧ��0��λ�ò��ܣ�1��λ�ü���subsets�����Կ���������
		����ʱ�临�Ӷ���n*n
	*/
	/*
		����һ���ⷨ����Ԫ�ص���һ��һ����ӽ�ȥ�ģ����Ϊ�գ�Ȼ�����1���ǾͶ��ˡ�1�����ּ���2���Ͷ��ˡ�1,2������2��������
		�����Ļ�n�Ľ׳˾��ܸ㶨
		Ϊ������ע����ǰ����
		һ��AC��8ms
	*/
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> re;
		sort(nums.begin(), nums.end());
		vector<int> nullVec;
		re.push_back(nullVec);
		for (int i = 0;i < nums.size();i++) {
			int n = re.size();
			for (int j = 0;j < n;j++) {
				vector<int> temp = re[j];
				temp.push_back(nums[i]);
				re.push_back(temp);
			}
		}
		return re;
	}
};

