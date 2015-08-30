/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
#pragma once
#include "LeetCode.h"
class MaximalSquare
{
public:
	/*
	�½�һ�����飨m+1��n+1������������������
	ÿ�����ֵ
		����Լ���0��ֱ����0
		�����1
			����������ı��ϣ���1
			�����Χ������0������1��
			�����Χ�������ұ��±����±ߣ�û��0��������Χ������С��ֵ+1
			��Ĺ����У���¼������ֵ
	��󷵻��������ֵ��ƽ������
	20ms �Լ�������� ������������!!!!!!!!�������
	���˵ĺ���˼��Ҳ����������������Ż��ˣ�û����ô�Ż���
	*/
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> v(m, vector<int>(n, 0));
		int re = 0;
		for (int i = m - 1;i >= 0;i--) {
			for (int j = n - 1;j >= 0;j--) {
				if (matrix[i][j] != '0') {
					if (i == m - 1 || j == n - 1 || !v[i + 1][j] || !v[i][j + 1] || !v[i + 1][j + 1]) {
						v[i][j] = 1;
					}
					else {
						v[i][j] = (v[i + 1][j] > v[i + 1][j + 1] ? (v[i + 1][j + 1] > v[i][j + 1] ? v[i][j + 1] : v[i + 1][j + 1]) :
							(v[i + 1][j] > v[i][j + 1] ? v[i][j + 1] : v[i + 1][j]))+1;
					}
					if (re < v[i][j]) re = v[i][j];
				}
			}
		}
		return re*re;
	}
};

