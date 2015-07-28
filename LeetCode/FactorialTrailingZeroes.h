/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
����һ�����֣���������ֵĽ׳�ĩβ�м���0
����������
5->0
10->00
15->000
20->0000
25->000000(ע�����25��ζ���Գ���*4�����������2��0)
30->0000000
35->00000000
40->000000000
45->0000000000
50->000000000000(ͬ�����2��0)
75��100��125��150->(2��0)
125�к�һ��25һ��5�����Ի�����3��0
625�к�����25 ���Ի�����4��0

���Զ���5�����һ��0
5ƽ��2��
����3
4�η�4
*/
#pragma once
class FactorialTrailingZeroes
{
public:
	FactorialTrailingZeroes();
	~FactorialTrailingZeroes();
	/*
	4 ms
	�Լ���ϱ��˵��뷨

	*/
	int trailingZeroes(int n) {
		int i = 0;
		int k = 5;
		while (k<=n){
			i += n / k;
			k *= 5;
		}
		return i;
	}
};

