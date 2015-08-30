/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
#pragma once
#include "LeetCode.h"
class UniquePaths
{
public:
	UniquePaths();
	~UniquePaths();
	/*
	ֱ���ý׳ˣ��վ���Խ�磬���Ի��ǹԹԵ�һ��һ������
	*/
	int uniquePaths(int m, int n) {
		return jianCheng(n - 1) / (jianCheng(m - 1)*jianCheng(n + m - 2));
	}
	int jianCheng(int n) {
		if (n == 0) return 1;
		else return n*jianCheng(n - 1);
	}
	/*
	���Ҫ�õ���̬�滮�� ��ϵݹ�
	0ms ûɶ������
	*/
	int uniquePaths_Dwyer(int m, int n) {
		//����Ҫ��һ�������¼���ʹ��Ľڵ㵽�յ��ж��پ��룡��
		vector<vector<int>> visited(m);
		for (int i = 0;i < m;i++)
			visited[i].assign(n,0);
		return uniquePaths_Dwyer(visited, 0, 0);
	}
	int uniquePaths_Dwyer(vector<vector<int>> &visited, int m, int n) {
		if (visited[m][n] == 0) {
			if (m == visited.size() - 1 && n == visited[0].size() - 1) return 1;
			int mPath = m < visited.size() - 1 ? uniquePaths_Dwyer(visited, m + 1, n) : 0;
			int nPath = n < visited[0].size() - 1 ? uniquePaths_Dwyer(visited, m, n + 1) : 0;
			visited[m][n] = mPath + nPath;
		}
		return visited[m][n];
	}
};

