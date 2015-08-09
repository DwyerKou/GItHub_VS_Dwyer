/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] �� num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -��.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
#pragma once
#include "LeetCode.h"
class FindPeakElement
{
public:
	FindPeakElement();
	~FindPeakElement();
	/*
	����⿴�Ƽ򵥣�����ϸ����϶�����ָ������lgn�ڸ㶨
	��ô��Ҫ�뵽���ֲ���
	����˼������Ϊ����peak���������ٴ��������ȼӺ����������ȼ���ӵĻ�����ô��һ���������ˣ�
	����ÿ�ζ��ֺ��ж����������߻��������ߣ������ߵĻ���left=mid������right=mid
	������ôac��
	8ms
	*/
	int findPeakElement(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		int n = nums.size();
		int left = 0, right = n - 1;
		int mid;
		if (nums[0]>nums[1]) return 0;
		if (nums[right]>nums[right - 1]) return right;
		while (left<right) {
			mid = (left + right) / 2;
			if ((nums[mid] > nums[mid - 1]) && (nums[mid]>nums[mid + 1]))//��仰���Ǽ��Ϻã�����
				return mid;
			else if (nums[mid] > nums[mid - 1])
				left = mid;
			else
				right = mid;
		}
		return left;
	}
};

