/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

��һ�����������ڵ��������ֵ���Ľ����������������������
�Ҳ��ñ������ˣ������ʱ��
*/
#pragma once
#include "LeetCode.h"
class BitwiseANDofNumbersRange
{
public:
	BitwiseANDofNumbersRange();
	~BitwiseANDofNumbersRange();
	/*
		���Ҫע�⵽��ֻҪn��m����ô���һλ��&��һ����0
		����ÿ�δ��������һλ����n��m��������һλ��Ȼ������жϾ�����
		���n��m���ʱ���ٰ����Ƶ�ȫ���ƻ�������
		68ms
	*/
	int rangeBitwiseAnd(int m, int n) {
		return n > m ? rangeBitwiseAnd(m / 2, n / 2) << 1 : m;
	}
};

