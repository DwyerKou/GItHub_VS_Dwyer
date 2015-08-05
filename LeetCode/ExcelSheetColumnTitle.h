/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*/
#pragma once
#include "LeetCode.h"
class ExcelSheetColumnTitle
{
public:
	ExcelSheetColumnTitle();
	~ExcelSheetColumnTitle();
	/*
	ע��ԡ�Z���Ĵ�����Ϊzȡģ����0��������Ҫ��������26
	������������������Ҫ��n--����
	*/
	string convertToTitle(int n) {
		if (n < 1) return "";
		string str;
		while (n) {
			int m = n % 26;
			str = (m==0?'Z':char(m + 64)) + str;
			n /= 26-(m==0?1:0);
		}
		return str;
	}

	/*
	������ǰ��n-1��Ȼ�����㣬��������������26������
	*/
	string convertToTitle2(int n) {
		if (n < 1) return "";
		string str;
		while (n) {
			--n;//ע����while��--
			str = char(n%26 + 65) + str;
			n /= 26;
		}
		return str;
	}
};

