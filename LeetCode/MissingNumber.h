/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?


*/
#pragma once
#include "LeetCode.h"
class MissingNumber
{
public:
	MissingNumber();
	~MissingNumber();
	/*
	32ms һ��ͨ����
	�õ������
	��ʵ���뻹������ӳ�䵽λ�ķ���
	������д�����Ƚ��鷳
	*/
	int missingNumber(vector<int>& nums) {
		if (nums.empty()) return -1;
		int n = nums.size();
		int re = nums[0]^0;
		for (size_t i = 1;i < n;++i)
			re = re^nums[i] ^ i;
		re = re^n;
		return re;
	}
};

