/*
7.22
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

������Ҫ�ö�ջ
*/
#pragma once
#include "LeetCode.h"
class ValidParentheses
{
public:
	ValidParentheses();
	~ValidParentheses();
	/*
	0ms
	ûʲô�ý��͵�
	ע��Ҫ���ǵ�ֱ������һ�����ַ�������Լ����stack���ǿյ����
	*/
	bool isValid(string s) {
		stack<char> st;
		for (auto c : s){
			if (c == ')'){
				if (st.empty() || st.top() != '(')
					return false;
				else{
					st.pop();
					continue;
				}
			}
			if (c == ']'){
				if (st.empty() || st.top() != '[')
					return false;
				else{
					st.pop();
					continue;
				}
			}
			if (c == '}'){
				if (st.empty() || st.top() != '{')
					return false;
				else{
					st.pop();
					continue;
				}
			}
			st.push(c);
		}
		return st.empty();
	}
};

