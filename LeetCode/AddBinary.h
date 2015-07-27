/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#pragma once
#include "LeetCode.h"
class AddBinary
{
public:
	AddBinary();
	~AddBinary();
	/*
		�ҳ��������ַ�ʽ��but������ʱ��
		�������ַ�ʽ�������������������������
		��һ�ַ����м��ٸ�1����0�أ�������������longlong��������
		��˼·
		*/
	string addBinary_Dwyer(string a, string b) {
		string str;
		stack<char> st;
		int na = 0, nb = 0;
		for (char c : a)
			na = na * 2 + (c - 48);
		for (char c : b)
			nb = nb * 2 + (c - 48);
		na += nb;
		while (na){
			if (na % 2)
				st.push('1');
			else
				st.push('0');
			na = na >> 1;
		}
		while (!st.empty()){
			str += st.top();
			st.pop();
		}
		return str;
	}

	/*
	4ms
	���
	����string��ȫ�������±���������񾭲�������stack��
	*/
	string addBinary_Dwyer1(string a, string b) {
		stack<char> sta, stb, stre;
		string str;
		for (char c : a)
			sta.push(c);
		for (char c : b)
			stb.push(c);
		int flag = 0;//��λ��־
		int x, y, z;
		while (!sta.empty() || !stb.empty()){
			x = sta.empty() ? 48 : sta.top();
			y = stb.empty() ? 48 : stb.top();
			z = x + y + flag;
			switch (z)
			{
			case 96:
				stre.push('0');
				break;
			case 97:
				stre.push('1');
				flag = 0;
				break;
			case 98:
				stre.push('0');
				flag = 1;
				break;
			case 99:
				stre.push('1');
				break;
			}
			if (!sta.empty()) sta.pop();
			if (!stb.empty()) stb.pop();
		}
		if (flag) stre.push('1');
		while (!stre.empty()){
			str += stre.top();
			stre.pop();
		}
		return str;
	}
	/*
	��Ҫ�Ľ�����Ĵ�����
	�������Ǳ��˵� ���Լ�д��һ��
	Ϊ�˾����������ƴ��
	4ms
	*/
	string addBinary_Dwyer2(string a, string b) {
		string str;
		int flag = 0;
		int i = a.size() - 1;
		int j = b.size() - 1;
		while (i>=0 || j>=0 || flag){
			//flag�ȼ�a�ģ��ټ�b��
			flag += i >= 0 ? a[i--] - 48 : 0;//�����i--��i>=0��Ȼ��-48
			flag += j >= 0 ? b[j--] - 48 : 0;
			str = char(flag%2+'0') + str;//�����õ�������ת�� char  ����һ���ص���� �������Ը�strǰ���char  �����0��2����0�������1��3����1
			flag /= 2;//flag�����0��1 ���µ�Ϊ0�������2��3�����µ�Ϊ1
		}
		return str;
	}
};

