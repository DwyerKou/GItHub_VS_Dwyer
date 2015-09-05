/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#pragma once
#include "LeetCode.h"
class WordSearch
{
public:
	/*
	* ���ݷ� �ӵ�һ�����ݵ��ϡ�С�����ҿ�ʼ�ң���Ҫһ��index��־����ƥ�䵽string���ĸ�λ����
	* ��Ҫһ���ܹ���¼�߹���·���Ķ�����ÿ���Ҳ���������ԭ·��������һ��һ����С��board����ȫ0��ȫ1��ʾ
	* false��ʾû���ʣ�true��ʾ���ʹ���
	* 20ms
	*/
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || word.empty()) return false;
		int m = board.size(), n = board[0].size();
		if (word.size() > m*n) return false;
		for (int i = 0;i < m;i++)
			for (int j = 0;j < n;j++)
				if (exist(board, i, j, word, 0, m, n))
					return true;
		return false;
	}
	bool exist(vector<vector<char>>& board, int x, int y, string &word, int index, const int &m, const int &n) {
		if (board[x][y] == ' ' || board[x][y] != word[index]) return false;
		if (index == word.size() - 1) return true;
		bool up = false, down = false, left = false, right = false;
		char temp = board[x][y];
		board[x][y] = ' ';
		//��ʼ��,��������������
		//!!!!!!!!!!!��������˺ö�ö�飡������������
		//һֱ��ʱ����ʱ��ԭ�������û���ڷ���true�ĵ�һʱ�䷵��
		if (x > 0){
			up = exist(board, x - 1, y, word, index + 1,m,n);
			if (up) return true;//ֻҪ��true�ͷ��أ����������� ���������������ʱ��������
		}
		if (x < m - 1){
			down = exist(board, x + 1, y, word, index + 1, m, n);
			if (down) return true;
		}
		if (y > 0){
			left = exist(board, x, y - 1, word, index + 1, m, n);
			if (left) return true;
		}
		if (y < n - 1){
			right = exist(board, x, y + 1, word, index + 1, m, n);
			if (right) return true;
		}
		board[x][y] = temp;
		return false;
	}
};

