/*
Implement pow(x, n).

Hide Tags
*/
#pragma once
#include "LeetCode.h"
class Powxn
{
public:
	Powxn();
	~Powxn();
	/*
	�ðɣ�n�����Ǹ������ҿ��ǵ���
	����xΪ0��1��-1���������ȴû�п��ǵ�
	ע��Ҫ���ǵ�x��double�͵ģ�double�ͱȽ���ȵ�ʱ��ķ���
	�����������ѵ���Ҫ������double�����ϣ�������������
	4ms ���
	*/
	double myPow(double x, int n) {
		vector<double> v;
		if (n == 0) return 1.0;
		if (abs(x - 0.0) < 0.0001) return 0.0;
		if (abs(x - 1.0) < 0.0000001) return 1.0;
		if (abs(x + 1.0) < 0.0000001) return n & 1 ? -1.0 : 1.0;
		int flag = false;
		if (n < 0) {
			flag = true;
			n = -n;
		}
		int i = 2;
		v.push_back(x);
		while (i < n) {
			v.push_back(*v.rbegin()**v.rbegin());
			i *= 2;
		}
		i /= 2;
		int k = n - i, count = 0;
		double re = *v.rbegin();
		while (k) {
			if (k & 1)
				re *= v[count];
			k = k >> 1;
			count++;
		}
		return flag ? (1.0 / re) : re;
	}
	/*
	����һ�ַ�����ֱ�Ӵ�n����
	ÿ�ζ���x��������ͬ�����������������ans*x
	ż��ֻ����
	Ҳ�������
	*/
	double myPow_Other(double x, int n) {
		double ans = 1;
		unsigned long long p;
		if (n < 0) {
			p = -n;
			x = 1 / x;
		}
		else {
			p = n;
		}
		while (p) {
			if (p & 1)
				ans *= x;
			x *= x;
			p >>= 1;
		}
		return ans;
	}
};

