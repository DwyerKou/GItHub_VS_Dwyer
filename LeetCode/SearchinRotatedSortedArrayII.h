/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
#pragma once
#include "LeetCode.h"
class SearchinRotatedSortedArrayII
{
public:
	SearchinRotatedSortedArrayII();
	~SearchinRotatedSortedArrayII();
	/*
	�ҵĽ����ǲ�Ӱ�죬ֱ���ù�����
	ԭ�����ǻ�Ӱ��ģ�����������������
	��Ϊ���ܰ���ͬ�ĸ��п��ˣ�
	����2,2,2,2,2,0,0,1,1,2,2,2

	�����µķ�����ǿ�б�������
	һ�����8ms
	perfect
	*/
	bool search(vector<int>& nums, int target) {
		int f = 0, b = nums.size() - 1, mid;
		if (nums[f] == nums[b] && target == nums[f]) return true;
		while (f < b) {
			mid = (f + b) / 2;
			if (nums[mid] == target || nums[f] == target || nums[b] == target) return true;//��ֹ���κ�һ�����
			if (nums[mid]>nums[f]) {//target���ܴ���nums[f] nums[mid] nums[b]�гɵ��ĸ������ڣ�Ҫ��ÿ����������ǵ�
				if (target > nums[f] && target < nums[mid]) b = mid;
				else if (target > nums[mid] || target < nums[f]) f = mid+1;
			}else if (nums[mid] < nums[f]) {//target���ܴ���nums[f] nums[mid] nums[b]�гɵ��ĸ������ڣ�Ҫ��ÿ����������ǵ�
				if (target < nums[mid]||target>nums[f]) b = mid;
				else if (target>nums[mid] && target < nums[f]) f = mid+1;
			}
			else if (nums[mid] == nums[f]) {
				f++;//�������ʱ�临�Ӷ���O(n)
			}
		}
		return nums[f] == target ? true:false;
	}
};

