/***********************
*Date:	2015.7.22
*Problems:	Write a function to find the longest common prefix string amongst an array of strings.
*����:	�ҵ������ַ����Ĺ���ǰ׺
*����
***********************/
#pragma once
#include "LeetCode.h"

class LongestCommonPrefix
{
public:
	LongestCommonPrefix();
	~LongestCommonPrefix();
	/*
	8ms
	���Ƚ���һ����Ϊpre��Ȼ��������ÿ���Ƚ϶�pre�����޸�
	*/
	string longestCommonPrefix_Dwyyer(vector<string>& strs) {
		if (strs.empty()) return "";
		auto begin = strs.begin();
		string pre = *(begin++);
		while (begin != strs.end() && pre != ""){
			size_t n = (pre.size() > (*begin).size() ? (*begin).size() : pre.size());
			pre.erase(n, pre.size() - n);//��pre�ĳ��Ƚ�ȡ���϶̵��Ǹ�
			for (size_t i = 0; i < n; ++i){
				if (pre[i] != (*begin)[i]){
					pre.erase(i, pre.size() - i);//һ�����ֲ�ͬ�����ȡ
					break;
				}
			}
			++begin;
		}
		return pre;
	}
};

