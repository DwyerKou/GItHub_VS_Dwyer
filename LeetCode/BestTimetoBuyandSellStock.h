/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
*/
#pragma once
#include "LeetCode.h"
class BestTimetoBuyandSellStock
{
public:
	BestTimetoBuyandSellStock();
	~BestTimetoBuyandSellStock();
	/*
		֪����Ʒ�ļ۸��ж��ܹ��õ����������
		Ҳ������i��j��i��j��ǰ�棬����j-i��ֵ��󣬷���������ֵ
		��̬�滮��˼��
		��ǰ����������¼��ǰ���ֵ���ͼ۸�
		���ұ����Ѿ����ֵ��������
		ac 8ms
	*/
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int currMin = prices[0];
		int re = INT_MIN;
		for (int i = 1;i < prices.size();i++) {
			currMin = min(currMin, prices[i]);
			re = max(re, prices[i] - currMin);
		}
		return re;
	}
};

