/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#pragma once
#include "LeetCode.h"
class FirstMissingPositive
{
public:
	FirstMissingPositive();
	~FirstMissingPositive();
	/*
	������partion�Ѵ���0���ҳ���
	Ȼ���֪��һ���ж��ٸ�����0��
	Ȼ����������������

	���������˹��ˣ�������������������Ȼ���ظ�Ԫ�ش��ڣ�������������������
	�����Ļ����ҵķ��������ҳ������������Ĳ���Ҳû��ͨ������������������ʧ�����֣��ݣ���
	*/
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		int index = partion(nums, 0);
		int n = nums.size();
		if (index == n) return 1;//ȫ�Ǹ���
		int num_positive = n - index;//����������
		int count = 1;
		int re = nums[index]^count++;
		for (int i = index + 1;i < n;i++)
			re = re^nums[index] ^ count++;
		re = re^count;
		return re;
	}
	int partion(vector<int>& nums,int pivot){
		int n = nums.size();
		int small = -1;
		for (int i = 0;i < n;i++) {
			if (nums[i] <= pivot) {
				small++;
				if (small != i)
					swap(nums[small], nums[i]);
			}
		}
		return small + 1;
	}

	/*
	�û���˼·�ˣ���������
	ֱ�ӿ����˵ģ���֮ǰ���ǹ����ַ���������Ϊʲô��ʱ���ò�������
	ֱ�ӰѶ�Ӧ������Ų����Ӧ���±꣡������Ѿ�һ���ˣ�������
	��1Ų��С��0,2Ų��1,4Ų��3       ע���ǽ�������swap
	�������ÿ��Ų������nums[i]�����ܷŵ���ȷ��λ���ϣ����Ҳ����ƻ����е�
	������������һ������
		��Ϊ����ǰ�ڰ�һ���ܴ�����ֽ������˺�ǰ��
		���ǲ��õ��ģ���Ϊ����һ������ȫ���������ģ������������һ�������ٰ�������ָ���������
		��������������ֻ�������ǰ�棬ֻ��˵������±��Ӧ�����ֲ����ڣ���ֱ�ӷ�������±��Ӧ������
	4ms
	*/
	int firstMissingPositive_Dwyer2(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
		for (int i = 0; i < n; i++)
			if (nums[i] != i + 1)
				return i + 1;
		return n + 1;
	}
};

