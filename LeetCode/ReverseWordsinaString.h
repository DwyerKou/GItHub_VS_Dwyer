/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/
#pragma once
#include "LeetCode.h"
class ReverseWordsinaString
{
public:
	ReverseWordsinaString();
	~ReverseWordsinaString();
	/*
	˼��ܼ򵥣���ȫ����תһ�飬Ȼ�������ո�֮����ٷ�תһ�鼴��
	ֻ������Ŀû˵����ո���ô����
	̫����
	����ͨ���ˣ���ֱ��
	*/
	void reverseWords(string &s) {
		if (s.empty()) return;
		//�鵰����Ŀ��û˵�������s��ʼ��ĩβ�������ո���ô����
		//Ҳû˵��һ�м��������ո���ô������
		//���Ե�ʱ�򣬷������ȫΪ�ո�Ļ�Ҫ�ѿո�ȥ������ô���Ȱ���β�Ŀո�ȥ��
		//�ڶ�����Ե�ʱ��������м��������ո���Ҫ����һ���ո������˹���
		//���Ի���˼·��ֻҪ�������ֿո�����һ���ո�ȥ���棬������ֻʣһ���ո���ô�Ͱ�s��Ϊ��
		auto b = s.begin();
		while (b != s.end()-1) {
			if (*b == ' '&&*(b + 1) == ' ')
				b = s.erase(b);
			else
				++b;
		}
		if (s[0]==' ') {
			s.erase(s.begin());
			if(s=="")
				return;
		}
		if (s[s.size() - 1] == ' ')
			s.erase(s.end() - 1);
		reverse(s.begin(), s.end());
		auto front = s.begin();
		auto back = s.begin() + 1;
		for (;back != s.end();++back) {
			if (*back == ' ') {
				reverse(front, back);
				front = back + 1;
				if (front != s.end())
					back = front;
				else return;
			}
		}
		reverse(front, back);
	}
};

