/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
#pragma once
#include "LeetCode.h"
class ProductofArrayExceptSelf
{
public:
	ProductofArrayExceptSelf();
	~ProductofArrayExceptSelf();
	/*
	�����ó������õĻ���easy��������Ҫ�����¿ռ䣬�����еĳ�������Ȼ���Ǹ������ĸ��Ϳ�����
	������չnums����n�Ժ�ֱ�push1��n-1������
	�����Ļ� i���µ�ֵ����i+1һֱ�����n-1��
	�����������ϻ���n*n ���У���������������
	*/
	vector<int> productExceptSelf_Dwyer(vector<int>& nums) {
		int n = nums.size();
		for (size_t i = 0;i < n - 1;i++)
			nums.push_back(nums[i]);
		for (size_t i = 0;i < n;i++)
			for (size_t j = i + 1;j < i + n;j++)
				nums[i] *= nums[j];
		return nums;
	}
	/*
	68ms ����� ����������
	���������飬һ�����ǰ����˵�ֵ����һ����Ӻ���ǰ�˵�ֵ
	Ȼ��iǰ��ĳ˻��ڵ�һ���������ǰ����i��λ��
	i����ĳ˻��ڵڶ��������ɺ���ǰi��λ��
	����������
	ʱ�为���3n
	�ռ临�Ӷ�2n
	*/
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> a,b;
		a.push_back(1);
		b.push_back(1);
		for (int i = 1;i < nums.size() - 1;i++) 
			a.push_back(a[i - 1] * nums[i - 1]);
		for (int i = 1;i < nums.size();i++)
			b.push_back(b[i - 1] * nums[nums.size() - i]);
		for (int i = 0;i < nums.size();i++)
			nums[i] = a[i] * b[nums.size() - i - 1];
		return nums;
	}

};

