/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
#pragma once
#include "LeetCode.h"
class ValidAnagram
{
public:
	ValidAnagram();
	~ValidAnagram();
	/*
	�����ҵĽⷨ����������map

	�ҿ������б�Ľⷨ����һ��map����һ�α���++���ڶ��α���--������ж��ǲ���ȫ0
	��������ù��ҵģ�ʡ��һ��ռ�

	����һ��������������stringֱ������Ȼ��Ƚ��ǲ�����ȣ��㶨
	*/
	bool isAnagram(string s, string t) {
		if ( s.size() != t.size()) return false;
		unordered_map<char, int> ms;
		unordered_map<char, int> mt;
		for (auto c : s)
			ms[c]++;
		for (auto c : t)
			mt[c]++;
		int n = s.size();
		auto it = ms.begin();
		while (it != ms.end()){
			if (it->second != mt[it->first])
				return false;
			++it;
		}
		return true;
	}
};

