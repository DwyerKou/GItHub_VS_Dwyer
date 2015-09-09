/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#pragma once
#include "LeetCode.h"
class SetMatrixZeroes
{
public:
	SetMatrixZeroes();
	~SetMatrixZeroes();
	/*
	88ms
	*/
	void setZeroes(vector<vector<int>>& matrix) {
		//��һ�������0�����ֶ�Ӧ�ĵ�һ�к͵�һ����Ϊ0�����ǣ�0,0��ͬʱ���ڵ�һ�к͵�һ�У�����ҪΪ������Ӹ���־λ
		int flag = -1;//-1ʲôҲ���ǣ�0ֻ�����У�1ֻ�����У�2ͬʱ����
		for (int i = 0;i < matrix.size();++i) {
			for (int j = 0;j < matrix[0].size();++j) {
				if (matrix[i][j]) continue;
				matrix[i][0] = 0;
				matrix[0][j] = 0;
				if (i == 0 || j == 0) {
					if (j != 0) {
						if (flag == -1) flag = 0;
						else if (flag == 1) flag = 2;
					}
					else if (i != 0) {
						if (flag == -1) flag = 1;
						else if (flag == 0) flag = 2;
					}
					else
						flag = 2;
				}
			}
		}
		//���ȸ��ݵ�һ�е�0������0���ڵ�����Ϊ0
		for (int i = 1;i < matrix[0].size();i++) {
			if (matrix[0][i] == 0)
				for (int j = 0;j < matrix.size();j++)
					matrix[j][i] = 0;
		}
		//Ȼ����ݵ�һ�е�0�����е�0���ڵ�0��Ϊ0
		for (int i = 1;i < matrix.size();i++) {
			if (matrix[i][0] == 0)
				for (int j = 0;j < matrix[0].size();j++)
					matrix[i][j] = 0;
		}
		//������״̬λ�ж�0,0 ��0�����
		if (matrix[0][0] == 0) {
			if (flag == 0 || flag == 2)
				for (int i = 1;i < matrix[0].size();i++)
					matrix[0][i] = 0;
			if (flag == 1 || flag == 2)
				for (int i = 1;i < matrix.size();i++)
					matrix[i][0] = 0;
		}
	}
};

