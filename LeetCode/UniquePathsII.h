/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
*/
#pragma once
#include "LeetCode.h"
class UniquePathsII
{
public:
	UniquePathsII();
	~UniquePathsII();
	/*
	�ⷽ����Ȼ��ʱ�ˣ���������������������������
	����Ϊ���ú���̫������
	*/
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		//����Ҫ��һ�������¼���ʹ��Ľڵ㵽�յ��ж��پ��룡��
		vector<vector<int>> visited(m, vector<int>(n, 0));
		return uniquePaths(visited, obstacleGrid, 0, 0, m, n);
	}
	int uniquePaths(vector<vector<int>> &visited, vector<vector<int>>& obstacleGrid, int m, int n, const int& row, const int& col) {
		if (obstacleGrid[m][n] == 1)
			return 0;
		if (visited[m][n] == 0) {
			if (m == row - 1 && n == col - 1) return 1;
			int mPath = m < row - 1 ? uniquePaths(visited, obstacleGrid, m + 1, n, row, col) : 0;
			int nPath = n < col - 1 ? uniquePaths(visited, obstacleGrid, m, n + 1, row, col) : 0;
			visited[m][n] = mPath + nPath;
		}
		return visited[m][n];
	}

	/*
	����һ���ǵݹ�ķ�������
	���ı��˵�
	����㷨���������ģ���ԭ����m��n��λ�ô���ǵ��յ��·���������������ǵ�����·��
	���㷨������⣬���Ǻ��㷨��
		������ҵĻ����һ��dp[m][n]��ֵΪ1��Ȼ��˫��ѭ���ֱ�m--��n--������dp[m-1][n] dp[m][n-1]������ӣ���󷵻�dp[1][1]��ֵ

	4ms
	*/
	int uniquePathsWithObstacles_Dwyer(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//ע������һ�У������һ�У�
		dp[0][1] = 1;
		//��ʵ��һ�µ�ѭ���ѵ�һ�У���һ��ȥ���ˣ���������������������Ƕ����һ��һ�е�ԭ��
		for (int i = 1; i <= m; ++i)//ѭ����ʱ������һ��Ҳ������
			for (int j = 1; j <= n; ++j)//���һ��Ҳ������
				if (!obstacleGrid[i - 1][j - 1])//�����1ֱ�Ӳ�����
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//��ǰ��i,j �͵���dp[i - 1][j] + dp[i][j - 1]
		return dp[m][n];
	}
};

