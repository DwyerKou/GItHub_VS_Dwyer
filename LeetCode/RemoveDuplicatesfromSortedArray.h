/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/
#pragma once
#include "LeetCode.h"
class RemoveDuplicatesfromSortedArray
{
public:
	RemoveDuplicatesfromSortedArray();
	~RemoveDuplicatesfromSortedArray();
	/*
	ֱ�ӵ��ñ�׼���unique����
	����
	����ĺ�
	32ms
	����
	ע��unique����һ����������ָ����Щ���Ƶ�������Ԫ�صĵ�һ��λ��
	*/
	int removeDuplicates(vector<int>& nums) {
		auto it = unique(nums.begin(), nums.end());
		auto begin = nums.begin();
		int i = 0;
		while (begin++ != it)
			++i;
		return i;
	}

	/*
	����Լ���
	һ�α���
	��ʵ�ϣ����˷��س��ȣ���Ҫ��nums�޸ĳɺ��ʵĲ���ac
	It doesn't matter what you leave beyond the new length.\
	ע����仰��������仰�Ϳ��Բ��ܳ������ȵĲ�����ʲôֵ��.���ԾͿ��Խ���count��λ�ã���Ϊ�³��ֵĲ�ͬ��ֵ
	���ģ�nums[count++] = nums[i];
	32ms

	*/
	int removeDuplicates_Dwyer2(vector<int>& nums) {
		if (nums.size()<2) return nums.size();
		int count = 1;
		for (int i = 1; i < nums.size(); ++i){
			if (nums[i] != nums[i - 1])
				nums[count++] = nums[i];
		}
		return count;
	}
};