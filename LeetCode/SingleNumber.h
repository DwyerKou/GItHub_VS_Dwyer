/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#pragma once
#include "LeetCode.h"
class SingleNumber
{
public:
	SingleNumber();
	~SingleNumber();
	/*
		�ҵķ�����sort��ʱ����
		Ȼ��while������
		leetcode 44ms������
	*/
	int singleNumber_Dwyer(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		auto begin = nums.begin();
		while (begin != nums.end()){
			if (*begin != *(begin + 1))
				return *begin;
			begin += 2;
		}
		return NULL;
	}

	/*
		���˵� ��������ʱ�䣬û���¿ռ� 
		^��������
		���ģ�һ����������һ������������Σ�������ֻ���������������������������
		20ms
	*/
	int singleNumber(vector<int>& nums) {
		for (size_t i = 1; i < nums.size(); ++i)
			nums[0] ^= nums[i];
		return nums[0];
	}
};

