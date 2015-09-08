/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?]

��תͼ��90��
*/
#pragma once
#include "LeetCode.h"
class RotateImage
{
public:
	RotateImage();
	~RotateImage();
	/*
		�ҹ��ɣ�ÿ��(x1,y1)Ҫ������y1,n-1-x1����λ��
		n*n�� ��һ�δӣ�0,0������0��n-2)
				�ڶ��δӣ�1,1������1��n-3��
				...
				���һ�δӣ�n/2-1,n/2-1�� �� (n/2-1,(n-2)-(n/2-1))

		һ��� 8ms����
	*/
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n <= 1) return;
		for (int i = 0;i < n / 2;i++) {
			for (int j = i;j <= n - 2 - i;j++) {
				int temp = matrix[j][n-1-i];
				matrix[j][n - 1 - i] = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = temp;
			}
		}
	}

	/*
	* ���Ǳ������￴���� ��һ�����·�����
	* clockwise rotate
	* first reverse up to down, then swap the symmetry
	* 1 2 3     7 8 9     7 4 1
	* 4 5 6  => 4 5 6  => 8 5 2
	* 7 8 9     1 2 3     9 6 3
	*/
	void rotate(vector<vector<int> > &matrix) {
		reverse(matrix.begin(), matrix.end());//��С������
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}

	/*
	* ��������ʱ��Ļ��������������������Ȼ���նԽ��߽���
	* anticlockwise rotate
	* first reverse left to right, then swap the symmetry
	* 1 2 3     3 2 1     3 6 9
	* 4 5 6  => 6 5 4  => 2 5 8
	* 7 8 9     9 8 7     1 4 7
	*/
	void anti_rotate(vector<vector<int> > &matrix) {
		for (auto vi : matrix) reverse(vi.begin(), vi.end());
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}
};

