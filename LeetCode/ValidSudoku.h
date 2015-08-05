/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

ǧ��Ҫע���������ν�����������Ѿ��������ֵķ��Ϲ��򣬲�ûҪ�����������ڴ��ڽ����пհ������������������
*/
#pragma once
#include "LeetCode.h"
class ValidSudoku
{
public:
	ValidSudoku();
	~ValidSudoku();
	/*
		ǿ�б�����
		12ms  ��� �м��伫���ٵĹ�����10ms �󲿷�12
		ע����������������΢��Щ����
		����һ��Ҫ��ʼ����!!
	*/
	bool isValidSudoku(vector<vector<char>>& board) {
		//һ��һ�б�����
		for (int i = 0;i < 9;++i) {
			int a[58] = {0};//1-9��9��49-57�����һ������46 ����±�57
			for (int j = 0;j < 9;++j) {
				if (board[i][j] != '.')
					if (++a[board[i][j]] == 2)
						return false;
			}
		}

		//һ��һ��
		for (int j = 0;j < 9;++j) {
			int a[58] = {0};//1-9��9��49-57�����һ������46 ����±�57
			for (int i = 0;i < 9;++i) {
				if (board[i][j] != '.')
					if (++a[board[i][j]] == 2)
						return false;
			}
		}

		//���������
		int count = -1;
		while (++count < 9) {
			int a[58] = {0};//1-9��9��49-57�����һ������46 ����±�57
			int i = count / 3 * 3;
			int j = count % 3 * 3;
			for (int m = i;m < i+3;m++)
				for (int n = j;n < j+3;n++){
					if (board[m][n] != '.')
						if (++a[board[m][n]] == 2)
							return false;
				}
		}
		return true;
	}
};

