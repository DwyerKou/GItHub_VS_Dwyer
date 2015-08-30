/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

1�Ļ��Ͳ������ˣ�������1������ȥ����
0�Ļ��ǿո�
*/
#pragma once
#include "LeetCode.h"
class LetterCombinationsofaPhoneNumber
{
public:
	LetterCombinationsofaPhoneNumber();
	~LetterCombinationsofaPhoneNumber();
	/*
	��������
	һ��� 0ms
	���ݷ�
	*/
	vector<string> letterCombinations(string digits) {
		//���԰���������ĸ�Ķ�Ӧ��ϵ��ӳ�䵽map��
		unordered_map<char, vector<char>> m{ {'2', { 'a','b','c' }}, { '3',{ 'd','e','f' } }, { '4',{ 'g','h','i' } }, { '5',{ 'j','k','l' } }, { '6',{ 'm','n','o' } },
		{ '7',{ 'p','q','r','s' } }, { '8',{ 't','u','v' } }, { '9',{ 'w','x','y','z' } }, { '0',{ ' '} } };
		vector<string> re;
		string path;
		if (digits.empty()) return re;//��ʼ���ǿ�����������
		letterCombinations(digits, 0, path, re,m);
		return re;
	}
	void letterCombinations(string &digits,int index,string &path, vector<string> &re, unordered_map<char, vector<char>>& m) {
		if (index == digits.size()) {
			re.push_back(path);
			return;
		};
		if(digits[index]=='1')
			letterCombinations(digits, index+1, path, re,m);
		else {
			for (auto c : m[digits[index]]) {
				path.push_back(c);
				letterCombinations(digits, index + 1, path, re, m);
				path.pop_back();
			}
		}
	}
};

