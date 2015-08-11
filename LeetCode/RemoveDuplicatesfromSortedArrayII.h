/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/
#pragma once
#include "LeetCode.h"
class RemoveDuplicatesfromSortedArrayII
{
public:
	RemoveDuplicatesfromSortedArrayII();
	~RemoveDuplicatesfromSortedArrayII();
	/*
	index��ǰ������и���
	count�������˶��ٴ�
	20ms 
	*/
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 3) return nums.size();
		int index=0, count = 1;
		int n = nums.size();
		bool flag = true;//���ڵ�һ�α�עindex��λ���Ժ���ò�����
		for (size_t i = 1;i < n;++i) {
			if (nums[i] == nums[i - 1]){
				count++;
				if(count<3&&!flag)
					nums[index++] = nums[i];
			}
			else {
				count = 1;
				if(!flag)
					nums[index++] = nums[i];
			}
			if (count == 3&&flag) {
				index = i;
				flag = false;
			}
		}
		return flag?n:index;
	}

	/*
	�ðɿ����ø��򵥵ĸ㶨����Ҫ��count������������ֱ�Ӻ����ϸ��ȽϾ����˰�����
	*/
	int removeDuplicates2(vector<int>& nums) {
		int i = 0;
		for (int n : nums)
			if (i < 2 || n > nums[i - 2])
				nums[i++] = n;
		return i;
	}
};

