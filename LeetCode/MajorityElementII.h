/*
Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/
#pragma once
#include "LeetCode.h"
/*
Ѱ�ҳ��ֳ�������֮һ������
���2��
�Ǿ�ά������num,ÿ�γ�����ȵ�++�����ȵ�--,���0�Ļ��л�
��ô��������еĻ�һ����num1��num2
��ʱ������һ����һ�¾������Ŀ
24ms
*/
class MajorityElementII
{
public:
	MajorityElementII();
	~MajorityElementII();
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> re;
		int num1 = 0, num2 = 1;
		int count1 = 0, count2 = 0;
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] == num1) count1++;
			else if (nums[i] == num2) count2++;
			else if (count1 == 0) { num1 = nums[i];count1++; }
			else if (count2 == 0) { num2 = nums[i];count2++; }
			else { count1--;count2--; }
		}
		//����������Ĳ��裬������ڵĻ�����ô��Ȼ��num1��num2��Ҳ�п��ܲ�����
		count1 = 0, count2 = 0;
		for (int i = 0;i < nums.size();i++) {
			if (nums[i] == num1) count1++;
			if (nums[i] == num2) count2++;
		}
		if (count1 > nums.size() / 3) re.push_back(num1);
		if (count2 > nums.size() / 3) re.push_back(num2);
		return re;
	}
};

