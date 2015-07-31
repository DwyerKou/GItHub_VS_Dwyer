/*
	House Robber 
	You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

	Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

	˵���� �����Ŀ���Ǹ�һ��vector�ҳ������������������ֵ����ֵint rob(vector<int>& nums) {
       ����������������˵�׸����� ���������˼�������˺�ô
	   ��˼�������͵���ٸ����Ӷ��У�ֻҪû�����ڵľͿ���
    }
*/
#pragma once
#include "LeetCode.h"

class HouseRobber
{
public:
	HouseRobber();
	~HouseRobber();
	/*
		����Ҫ����ֵa,b
		���������ߵ�n�ˣ���a����ľ���͵n-1�����ر���b����ľ��ǲ�͵n-1�����ر�
		��ô����Ҫ����Ҫ��Ҫ͵n��͵�˵Ļ����ر���b+nums��n��
		��͵�Ļ���a
		����Ҫ�Ƚ�b+nums��n����a��ֵ˭����
	*/
	int rob(vector<int>& nums) {
		int a = 0, b = 0;
		for (int i = 0;i < nums.size();i++) {
			if (b + nums[i] >= a){//���͵��i��ֵ����
				int temp = a;
				a = b + nums[i];//a�͸��³�͵��i����ֵ
				b = temp;//b�����ԭ����a
			}
			else {//���͵�˻����粻͵
				b = a;//a���������Ӧ�û���ԭ���ģ�bҲ���a��
			}
		}
		return max(a, b);
	}
};

