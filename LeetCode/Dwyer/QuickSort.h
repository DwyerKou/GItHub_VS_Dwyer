#pragma once
#include"../LeetCode.h"
class QuickSort
{
public:
	QuickSort();
	~QuickSort();
	void quickSort(vector<int> &nums) {
		if (nums.size() < 2) return;
		return sort(nums, 0, nums.size() - 1);
	}

	void sort(vector<int> &nums, int front, int back) {
		int index = partition(nums, front, back);
		if (index - front > 1)
			sort(nums, front, index);
		if (back - index > 1)
			sort(nums, index + 1, back);
		return;
	}
	//�����stlԴ��
	int partition(vector<int> &nums, int front, int back) {
		int index = (front + back) / 2;
		swap(nums[index], nums[back]);//��key�����һλ
		int small = front - 1;// smallָ��ǰɨ�赽��С��key�����һ��
		for (index = front;index < back;index++) {//index�ߵ����һλ֮ǰ
			if (nums[index] < nums[back]) {//�������key��index����
				++small;//�������С��key������ʱ���û��ˣ�small����һλ�ǵ�һ������key��
				if(small!=index)//Ϊ�˷�ֹ��index��ʼ�ͳ���С�ڵ���������������small indexλ����ͬ��ֱ������
					swap(nums[small], nums[index]);
			}
		}
		++small;//����keyֵ�ŵ�small��λ����
		swap(nums[small], nums[back]);
		return small;
	}
};

