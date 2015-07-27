/*
	Rotate an array of n elements to the right by k steps.

	For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

	Note:
	Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

	[show hint]

	Hint:
	Could you do it in-place with O(1) extra space?
	Related problem: Reverse Words in a String II


	*/
#pragma once
#include "LeetCode.h"
class RotateArray
{
public:
	RotateArray();
	~RotateArray();
	/*
		�����ҵ�����һ�ַ���
		Ч��Ϊë��ô�Ͱ�
		72ms
		�ܿ���
		������insert��erase���µģ���Ϊÿ����ô�����ᵼ��vector���ڴ��е����·���
		������
		��������ȽϾ���������û�п��ٿռ䣬����ʱ��ķ���Ҫ����vector
		*/
	void rotate_Dwyer(vector<int>& nums, int k) {
		if (nums.size() < 2) return;
		k = k%nums.size();
		if (k == 0) return;
		while (k){
			nums.insert(nums.begin(), *(nums.rbegin()));
			nums.erase(nums.end() - 1);
			--k;
		}
	}
	/*
		������һ�ο���������ķ�ʽ
		24 ms
		����ͱ����
		����������
		*/
	void rotate_Dwyer1(vector<int>& nums, int k) {
		if (nums.size() < 2) return;
		k = k%nums.size();
		if (k == 0) return;
		vector<int> v(nums.size(), 0);
		copy(nums.begin(), nums.end() - k, v.begin() + k);
		copy(nums.end() - k, nums.end(), v.begin());
		copy(v.begin(), v.end(), nums.begin());
	}

	/*
		���˵� �ڲ��ϵؽ���ֵ
		˼�룬ÿ�ν����k������ǰ��k���û�
		Ȼ���µ����k���룬0+k��λ�ÿ�ʼ�û�
		Ȼ�����k����0+k+k��
		����������k������ʣ�µ�λ��
		Ҳ����k %= n; n -= k
		*/
	/*void rotate_Dwyer2(vector<int>& nums, int k) {
		int n = nums.size();
		for (; k %= n; n -= k, nums+= k)
			for (int i = 0; i < k; i++)
				swap(nums[i], nums[n - k + i]);
	}*/
};

