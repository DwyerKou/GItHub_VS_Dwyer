/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
#pragma once
#include "LeetCode.h"
class SortColors
{
public:
	SortColors();
	~SortColors();
	/*
	�Ѿ�֪��ֻ��0,1,2��
	�����ȹ�һ���������ж��ٸ�0�����ٸ�1�����ٸ�2��Ȼ�������Ų�һ�¾�����
	����������

	�ڶ��ַ���������ָ�룬һ��ָ��0�����滻��λ�ã�1��ָ��2�����滻��λ�ã�����������һ�飬��������ڶ����غ�ʱ��ֹͣ
	4ms�������
	*/
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return;
		int p0 = 0, p2 = n - 1;
		while (nums[p0] == 0) p0++;
		while (nums[p2] == 2) p2--;
		if (p0 >= n - 1 || p2 <= 0 || p0 >= p2) return;
		int p = p0;
		while (p <= p2) {
			if (nums[p] == 0) {
				swap(nums[p0], nums[p]);
				p0++;
				p++;//ע�����p�ܱ�֤ǰ��ֻ��0��1��p0�ܱ�֤ǰ��ȫ��0��p0��p1��ȫ��1.����swap�Ժ�Ҫ��������++
			}
			else if (nums[p] == 2) {
				swap(nums[p2], nums[p]);
				if (nums[p] == 1) p++;//ע�������p2���ﻻ����1�Ļ�p++��
				while (nums[p2] == 2) p2--;//�����Ժ�p2�ٶȼ��
			}
			else
				p++;
		}
	}
};

