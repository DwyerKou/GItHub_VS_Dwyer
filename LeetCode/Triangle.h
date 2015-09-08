/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
�ҵ�һ���������ɶ���׵���С·��
*/
#pragma once
#include "LeetCode.h"
class Triangle
{
public:
	//��Ϊ������û�й��ɣ�����ÿһ��·�����п��ܣ�Ҫ����ȫ�������ݷ�
	//������������ַ�������ֳ�ʱ
	int minimumTotal(vector<vector<int>>& triangle) {
		int high = triangle.size();
		int maxSum = INT_MIN;
		if (high == 0) return maxSum;
		int sum = triangle[0][0];
		vector<vector<int>> visited;
		minimumTotal(triangle, maxSum, sum, 1, 0, high);
		return maxSum;
	}
	void minimumTotal(const vector<vector<int>>& triangle, int &maxSum, int &sum, int level, int index, const int &high) {
		if (level == high) {
			if (sum > maxSum)
				maxSum = sum;
			return;
		}
		//��Ա���level��index����Ϊindex������Ϊindex+1
		sum += triangle[level][index];
		minimumTotal(triangle, maxSum, sum, level + 1, index, high);
		sum -= triangle[level][index];

		sum += triangle[level][index + 1];
		minimumTotal(triangle, maxSum, sum, level + 1, index + 1, high);
		sum -= triangle[level][index + 1];
	}
	/*
	����˼·���������濪ʼ�����ң��ҳ�ÿ���ڵ���ܳ��ֵ����ֵ
	����������ƻ�ԭ�е�����
	����ռ�ռ�
	ͨ���� 8ms
	*/
	int minimumTotal(vector<vector<int>>& triangle) {
		int high = triangle.size();
		for (int i = high - 2;i >= 0;i--) {
			for (int j = 0;j <= i;j++)
				triangle[i][j] += min( triangle[i + 1][j],triangle[i + 1][j + 1]);
		}
		return triangle[0][0];
	}
};

