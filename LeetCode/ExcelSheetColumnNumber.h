/***********************
*Date:	2015.6.28
*Problems:	Given a column title as appear in an Excel sheet, return its corresponding column number.
	For example:

		A -> 1
	    B -> 2
	    C -> 3
	    ...
	    Z -> 26
	    AA -> 27
	    AB -> 28 
*����:	ʵ������26����  �����ַ���Ӧ��16���ƿ��Ժ�����֪��-64���Ƕ�Ӧ������ Ȼ��charǿ��תΪint����
*��Ŀ��	����һ����ĸ��ɵ��ַ����������Ӧ������
*����	����ҵ��㷨�Ѿ��൱��Ч�ˣ�����������
***********************/

#pragma once

#include <string>
#include <math.h>

using namespace std;

class ExcelSheetColumnNumber
{
public:
	ExcelSheetColumnNumber();
	~ExcelSheetColumnNumber();
	int titleToNumber_Dwyer(string s) {
		int size = s.size(), sum = 0;
		for (auto c : s)
			sum += (c - 64) * pow(26,--size);
		return sum;
	}
};

