/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#pragma once
#include "LeetCode.h"
class TwoSum
{
public:
	TwoSum();
	~TwoSum();
	/*
	1.�����ñ�������������ʱ�临�Ӷ�Ϊnƽ��
	2.ʹ��map��ʱ�䣡��
	16ms
	ע��Ҫ���ǵ����ܳ���������ȵ�ֵ����� ���� 1,2,3,4,3   6 ��ôҪ������3��λ�����
	��������������ܱ����������������
	��������ȱ���һ��ȫ�����map��Ȼ���ڱ���map���Ϳ��ܳ�����һ��3��ʧ�����
	*/
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
		unordered_map<int, int> m;
		for (size_t i = 0;i < nums.size();++i) {
			int temp = target - nums[i];
			if (m.find(temp) != m.end()) {
				v.push_back(m[temp] + 1);
				v.push_back(i + 1);
				break;
			}
			m[nums[i]] = i;
		}
		return v;
	}
};

