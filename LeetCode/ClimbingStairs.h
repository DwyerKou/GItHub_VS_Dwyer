/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

���������õݹ���ò�����(����˼���Ĳ�����ȫ) 

Ȼ�������ǣ��ݹ���ü������һ��һ����ظ����㣡��
����forѭ��
*/
#pragma once
#include "LeetCode.h"
class ClimbingStairs
{
public:
	ClimbingStairs();
	~ClimbingStairs();
	/*
	���������ȷ���ǻᳬʱ
	��Ϊ��Ѽ������һ��һ�μ���
	*/
	int climbStairs_Dwyer1(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		return climbStairs_Dwyer1(n - 1) + climbStairs_Dwyer1(n - 2);
	}

	/*
	��forѭ�� ����0ms
	��ʵ�����һ��쳲���������
	*/
	int climbStairs_Dwyer2(int n) {
		if (n <= 0 || n==1 ||n==2) return n;
		vector<int> v(n+1, 0);
		v[1] = 1;
		v[2] = 2;
		for (size_t i = 3; i <= n; ++i){
			v[i] = v[i - 1] + v[i - 2];
		}
		return v[n];
	}
};

