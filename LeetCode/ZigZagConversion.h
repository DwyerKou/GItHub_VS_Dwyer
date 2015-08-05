/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#pragma once
#include "LeetCode.h"
class ZigZagConversion
{
public:
	ZigZagConversion();
	~ZigZagConversion();
	/*
	52ms ������
	���ȳ�ʼ����numrows������
	Ȼ�����s��ͬʱ��һ��count�ȼ��ټ��ټ��ټ����������Ƶ�ǰs���ַ�Ӧ�����ĸ������
	������εõ�����������ַ�����
	*/
	string convert_Dwyer(string s, int numRows) {
		if (numRows < 1) return "";
		if (s.empty() || numRows == 1) return s;
		vector<vector<char>> v(numRows);
		int n = s.size();
		int count = 0;
		bool flag = true;
		for (size_t i = 0;i < n;++i) {
			v[count].push_back(s[i]);
			if (flag)
				if (count == numRows - 1) {
					flag = false;
					--count;
				}
				else
					count++;
			else if (!flag)
				if (count == 0) {
					flag = true;
					count++;
				}
				else
					count--;
		}
		string str;
		for (size_t i = 0;i < numRows;++i) {
			auto it = v[i].begin();
			while (it != v[i].end()) {
				str += *it;
				++it;
			}
		}
		return str;
	}


	/*
	���ַ������ҹ۲�����Ĺ��ɣ�Ӧ������ͳ����
	�Ե�1�У���һ����������numRows*2-2���ڶ�������0...
	�Ե�2�У���һ����������numRows*2-4���ڶ�������2...
	������
	�Ե�numRows�У���һ����������0���ڶ�������numRows*2-2...
	
	�㶨
	16ms ���
	ע���һ�κ����һ�λ�Ƚ��ر𣬲��ܼ���firstȻ��second
	*/
	string convert_Dwyer1(string s, int numRows) {
		if (numRows < 1) return "";
		if (s.empty() || numRows == 1) return s;
		if (numRows >= s.size()) return s;

		int n = s.size();
		int first = numRows * 2 - 2;
		int second = 0;
		string str;
		for (size_t i = 0;i < numRows;++i) {
			int index = i;
			int flag = 1;//0��ʱ����first��1��ʱ����second
			while (index < n) {
				str += s[index];
				if (i == 0 || i == numRows - 1)
					index += (numRows * 2 - 2);
				else if (flag)
					index += first;
				else 
					index += second;
				flag = flag ? 0 : 1;
			}
			first -= 2;
			second += 2;
		}
		return str;
	}
};

