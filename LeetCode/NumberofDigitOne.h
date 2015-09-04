/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:

Beware of overflow.
*/
#pragma once
#include "LeetCode.h"
class NumberofDigitOne
{
public:
	NumberofDigitOne();
	~NumberofDigitOne();
	/*
	�����Ŀ����������һ���ж��ٸ�1
	������һ���ж��ٸ����ֺ���1
	0ms
	�Ӹ�λ����λ���η���
	*/
	int countDigitOne(int n) {
		int maxBase = pow(10, countDigits(n) - 1);//����n��5λ��65314���Ǿʹ�10000��ʼ����
		int product = 1;//�������ͳ��ÿ��Ӧ�ó˶���
		int sum = 0;
		while (maxBase > 0) {
			//ȡ���λ
			int i = n / maxBase;
			if (i > 1)//���ֲ�ͬ�ķ�ʽ�ֱ����sum
				sum += maxBase*product;
			else if (i == 1)
				sum += (n - maxBase + 1) + maxBase*(product - 1);
			else if (i == 0)
				sum += maxBase*(product-1);
			product = (product - 1) * 10 + i + 1;//�����ǳ������ĵĵط������ݹ����ܽ�
			if (i)//���i��ֵ��0����n����
				n -= i*maxBase;
			maxBase /= 10;
		}
		return sum;
	}
	//���ڻ�ȡnһ���м�λ����
	int countDigits(int n) {
		int re = 0;
		while (n) {
			re++;
			n /= 10;
		}
		return re;
	}
};

