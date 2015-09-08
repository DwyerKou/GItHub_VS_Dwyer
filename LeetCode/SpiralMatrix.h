/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
���������ά����
*/
#pragma once
#include "LeetCode.h"
class SpiralMatrix
{
public:
	SpiralMatrix();
	~SpiralMatrix();
	//x��y�ķ�Χһֱ�ڱ䣬����ά��һ��x��y�ķ�Χ
	/*
	0ms����һ���
	*/
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> re;
		if (matrix.size() == 0) return re;
		int xMin = 0, xMax = matrix.size() - 1;
		int yMin = 0, yMax = matrix[0].size() - 1;
		int n = (xMax + 1)*(yMax + 1);
		int x = 0, y = 0;
		int flag = 0;//0�ң�1�£�2��3��
		for (size_t i = 0;i < n;i++) {//ÿ����һ��Ԫ��
			re.push_back(matrix[x][y]);
			if (x == xMin&&y == yMin&&flag==3) {
				flag = 0;
				yMin++;
			}
			else if (x == xMin&&y == yMax&&flag==0) {
				flag = 1;
				xMin++;
			}
			else if (x == xMax&&y == yMax&&flag==1) {
				yMax--;
				flag = 2;
			}
			else if (x == xMax&&y == yMin&&flag==2) {
				xMax--;
				flag = 3;
			}
			switch (flag)
			{
			case 0:
				y++;
				break;
			case 1:
				x++;
				break;
			case 2:
				y--;
				break;
			case 3:
				x--;
				break;
			default:
				break;
			}
		}
		return re;
	}
};

