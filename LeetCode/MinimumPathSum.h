/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#pragma once
#include "LeetCode.h"
class MinimumPathSum
{
public:
	MinimumPathSum();
	~MinimumPathSum();
	/*
	�����ϵ����µ����·��
	���Խ�һ�����飬���ÿ���㵽���µ����·����
		�����µ�����һ��һ����д
	28ms ���
	*/
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> min(m + 1, vector<int>(n + 1, INT_MAX));//��ʼ��Ϊ���
		min[m - 1][n] = 0;//ע�����������0
		for (int i = m - 1;i >= 0;--i)
			for (int j = n - 1;j >= 0;--j)
				min[i][j] = min[i + 1][j] > min[i][j + 1] ? min[i][j + 1] + grid[i][j] : min[i + 1][j] + grid[i][j];//�滻ԭ��
		return min[0][0];
	}
};

