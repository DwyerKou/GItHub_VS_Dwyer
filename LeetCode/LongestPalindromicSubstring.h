/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.
*/
#pragma once
#include "LeetCode.h"
class LongestPalindromicSubstring
{
public:
	LongestPalindromicSubstring();
	~LongestPalindromicSubstring();
	/*
	��ʵ֤�� �ҵķ����Ǵ�ģ�ע����Ĳ���һ����������������������abbcҲ�ǣ�bbҲ�ǣ�abccbaҲ�ǣ��ҵķ���û�������������
	//�������뵽�ķ���
	//����s��Ȼ���ÿ��char����������ұ��ǲ�����ȣ����˵���л��ģ�һֱ��������ȣ�ÿ�γ����µ��������־ͱ���
	*/
	string longestPalindrome_DwyerWrong(string s) {
		if (s.size()<=1) return s;
		int maxLength = 1;
		int pos, length;
		int n = s.size();
		for (int i = 1;i < n-1;i++) {
			int j = 1;
			while (i - j >= 0 && i + j < n&& s[i - j] == s[i + j])
				++j;
			if (maxLength < 1 + (j - 1) * 2){
				maxLength = 1 + (j - 1) * 2;
				pos = i;
				length = j-1;
			}
		}
		return s.substr(pos-length,maxLength);
	}

	/*
		�����
		8ms  һ��� ����ʱ��
		�����Ǳ���s��
		���s����һ����s����ȣ�������ķ���
		���s����һ����ȣ�����s��λ��pos1�����������ߣ��ҵ����һ����ȵ�λ��pos2��Ȼ�����ұȽ�
		�´�iֱ������pos2+1��λ�ÿ�ʼ
	*/
	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;
		int pos1,pos2,maxLength=1, lengthOneside,n = s.size();
		for (int i = 0;i < n - 1;i++) {
			int pos1temp = i;
			while (i<n-1&&s[pos1temp] == s[i+1])
				++i;
			int pos2temp = i;
			int j = 1;
			while (pos1temp - j >= 0 && pos2temp + j < n && s[pos1temp - j] == s[pos2temp + j])
				++j;
			int newLength = pos2temp - pos1temp + 1 + (j - 1) * 2;
			if (newLength > maxLength) {
				maxLength = newLength;
				pos1 = pos1temp;
				pos2 = pos2temp;
				lengthOneside = j-1;
			}
		}
		return s.substr(pos1 - lengthOneside, maxLength);
	}
};

