/***********************
*Date:2015.7.14
*Problems:Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*��Ŀ����һ�����֣���������ַ����������ÿ��ǵ���������
*����	����õĻ�������while������һ��һ��ȡģȡ�࣬Ȼ��ó�һ��������Ȼ���ж��Ƿ����
		��������ô�õ���ת���ַ�����Ȼ�����ַ����������ô��atoi����ˣ�leetcode��Ȼ����ʶ�����
		����ôvs2013��������˰����ݡ�������д��һ���ʹ��˼��һ���ģ�˿������

***********************/

#pragma once
#include <string>
#include <sstream>
using namespace std;
class ReverseInteger
{
public:
	ReverseInteger();
	~ReverseInteger();
	//�����ͨ�����������leetcode��c++֧�ֲ���(�������ֲ������leetcode��vs��atoi�Ĵ���ͬ)
	//�Ժ�������ʹ��atoi������stoi��stoll �ȣ������c++11��׼\
	//12ms
	int reverse_Dwyer(int x) {
		long long re;
		bool nagitive = x<0;
		if (nagitive)
			x = -x;
		
		stringstream ss;
		ss << x;
		string  s = ss.str();
		auto b = s.rbegin();
		string rs;
		while (b != s.rend()){
			rs += *b;
			++b;
		}

		if (nagitive)
			re = -stoll(rs);
		else
			re = stoll(rs);
		return re>INT_MAX || re < INT_MIN ? 0 : re;
	}

	int reverse_Dwyer2(int x) {
		long long re = 0;//����һ��Ҫ��long long
		bool nagitive = x<0;
		if (nagitive)
			x = -x;
		while (x / 10){
			re = re * 10 + x % 10;
			x /= 10;
		}
		re = re * 10 + x;
		if (nagitive)
			re = -re;
		return re>INT_MAX || re < INT_MIN ?  0 :  re;
	}
};

