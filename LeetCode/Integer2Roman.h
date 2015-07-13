/***********************
*Date:2015.7.6
*Problems:Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*��Ŀ������һ�������������������ֵ�д��
*�����������֣�
�����ַ�   ��Ӧ�İ��������ֱ�ʾΪ
I			1
V			5
X			10
L			50
C			100
D			500
M			1000
*���򣺿����±������ĺ󣬾����Լ����˼·�Ѿ��ܰ���
***********************/

#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;

class Integer2Roman
{
public:
	Integer2Roman();
	~Integer2Roman();

	/********************
	*����:�������д�ķ���������˼·�ǹ��������map
	*LeetCodeЧ��:3999������64ms
	*���ģ��������ֿ���ÿ�δ���һ�����λ�����λ�޹�
	********************/
	string intToRoman_Dwyer(int num) {
		//���γ���vector�е�Ԫ��
		vector<int> v{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		//��ӳ���ϵ����һ��map��
		map<int, string> m = { { 1, "I" }, { 4, "IV" }, { 5, "V" }, { 9, "IX" }, { 10, "X" }, { 40, "XL" }, { 50, "L" }
		, { 90, "XC" }, { 100, "C" }, { 400, "CD" }, { 500, "D" }, { 900, "CM" }, { 1000, "M" } };
		//������ֵ
		string s;
		//���δ�����
		vector<int>::iterator it = v.begin();
		int num_front;//��num�ĵ�һλ�ַ�
		int num_front_int;//��һλ�������ֵ
		//ÿ�δ������λ
		while (num){
			num_front = num / (*it);
			num_front_int = num_front*(*it);
			//�������λ��λ���Լ���ֵȥȷ�����λ����������
			while (num_front){
				s += m.find(*it)->second;
				--num_front;
			}
			//���������λ��ȥ�����λ
			num %= *it;
			++it;
		}
		return s;
	}
};

