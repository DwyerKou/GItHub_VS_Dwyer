/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
#pragma once
#include "LeetCode.h"
class LengthofLastWord
{
public:
	LengthofLastWord();
	~LengthofLastWord();
	/*
	�ҵķ���
	˼·����
	��Ҫ��Ҫ���ǵ�����кܶ�ո�����
	4ms 
	*/
	int lengthOfLastWord_Dwyer(string s) {
		if (s.empty() || s.find(' ') == string::npos) return s.size();
		auto pos = s.find_last_of(' ');
		while (pos!=string::npos && pos == s.size() - 1){
			s.erase(s.end() - 1);
			pos = s.find_last_of(' ');
		}
		if (s.empty() || pos == string::npos) return s.size();
		return s.size() - pos - 1;
	}

	/*
	�ҵĵڶ��ַ���
	�����c++ primer��ʱ���ᵽ����Ҳ�������ˣ�ȷʵ��������Ӧ��ʹ�õķ���
	*/
	int lengthOfLastWord_Dwyer2(string s) {
		istringstream ss(s);
		string str;
		while (ss >> str)
			;
		return str.size();
	}
};

