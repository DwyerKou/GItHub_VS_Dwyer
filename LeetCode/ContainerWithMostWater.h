/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

�������ͣ�����ϵ�У�x����0-nÿ���㣬��Ӧ��ֵ��a[n]
Ȼ�󻭳�[i,0]��[i,a[i]]���߶�
ȡ���������߶Σ�ʹ����x��Ϊ�ף�����������ˮ
*/
#pragma once
#include "LeetCode.h"
class ContainerWithMostWater
{
public:
	ContainerWithMostWater();
	~ContainerWithMostWater();
	/*
	����o��n*n������������
	���leetcode������������������
	��ʱ��
	*/
	int maxArea_DwyerTimeLimit(vector<int>& height) {
		int n = height.size();
		if (n < 2) return 0;
		int maxArea = INT_MIN;
		for (int i = 0;i < n - 1;++i) {
			for (int j = i + 1;j < n;++j) {
				int a = area(height, i, j);
				if ( a> maxArea)
					maxArea = a;
			}
		}
		return maxArea;
	}

	/*
	������һ�������� Ȼ����û�뵽 ���ı��˵�
	32ms ���� ��������O��n��
	�����������̰������ߡ���Ϊ�����ߣ������ȼ�С����ô���С��ʱ��ֻ�����ϸ��ߵĸ߶Ȳ�����ɸ��Ӵ��container��
	������λ��𴦿��ģ���������������������ô�㹻�����
	*/
	int maxArea(vector<int>& height) {
		int n = height.size();
		if (n < 2) return 0;
		int maxArea = INT_MIN;
		int low = 0, high = n - 1;
		while (low < high) {
			maxArea = max(maxArea, (high-low)*min(height[high],height[low]));
			if (height[low] < height[high])
				++low;
			else
				--high;
		}
		return maxArea;
	}


	//���������ķ�����������Ĳ����������С���Ǹ�
	int area(vector<int>& height,int&x, int&y) {
		return min(height[x], height[y])*(y - x);
	}
};

