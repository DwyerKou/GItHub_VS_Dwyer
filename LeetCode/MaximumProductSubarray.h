/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
#pragma once
#include "LeetCode.h"
class MaximumProductSubarray
{
public:
	MaximumProductSubarray();
	~MaximumProductSubarray();
	/*
		��Ϊ�����������Բ����Ǹ����Ļ����϶�Խ��Խ��
		���������ı����Ǹ����Ĵ���
		Ҳ�������򣬻��ƻ�˳��
		��ô����л���û�и�����������ż��������
		4ms ���
	*/
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		//maxP��maxN����������һ�����ߵ���ǰλ���ܳ˳��������������һ���渺��
		int maxRe = INT_MIN, n = nums.size(), maxP = 0, maxN = 0;
		for (int i = 0;i < n;i++) {
			if (nums[i] == 0) {
				if (0 > maxRe) maxRe = 0;
				maxP = 0;maxN = 0;
				continue;
			}
			else if (nums[i] > 0) {//Ҫ���ǵ�Ϊ0�����
				maxP = maxP?maxP*nums[i]:nums[i];
				maxN = maxN ? maxN*nums[i] : 0;
			}
			else {
				int temp = maxP;
				maxP = maxN?maxN*nums[i]:0;
				maxN = temp?temp*nums[i]:nums[i];
			}
			if (maxP > maxRe) maxRe = maxP;
		}
		return maxRe;
	}
};

