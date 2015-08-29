/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum �� s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/
#pragma once
#include "LeetCode.h"
class MinimumSizeSubarraySum
{
public:
	MinimumSizeSubarraySum();
	~MinimumSizeSubarraySum();
	/*
		���������϶��� n*n
		��û�и��õ��أ�
		�����ÿռ任ʱ�䣡��
		����n
		ǧ��Ҫ�����˴��ڴ��ڵ���s��Ԫ�ص����
		4ms ���
	*/
	int minSubArrayLen(int s, vector<int>& nums) {
		if (s < 0 || nums.size() < 1) return 0;
		//�½�һ�����飬����ǰ����ĺ�,����������
		vector<int> v;
		int sum = 0, n = nums.size(), index = 0;
		for (int i = 0;i < n;i++) {
			if (nums[i] >= s) return 1;//��ǰ��ֹ
			sum += nums[i];
			v.push_back(sum);
			if (sum >= s && index == 0)
				index = i;//���һ�����ڵ���s��λ��
		}
		if (index == 0) return 0;
		int front = 0, minLen = index + 1;//��ʼ��С���Ժ�ÿ��Ҫ��֤����С�����
		for (;index < n;index++, front++) {//������Ӷ���O(n)
			while (v[index] - v[front] >= s) {
				front++;
				if (index - front + 1 < minLen) //ע��front���ƶ��ˣ�Ҫ+1
					minLen = index - front + 1;
			}
		}
		return minLen;
	}
};

