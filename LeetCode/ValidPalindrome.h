/***********************
*Date:	2015.6.28
*Problems:	Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*����:	Ҫ�ѱ����ţ��ո�ʲô�Ķ�ȥ���������ַ�
Ҫ���ǵ��մ�����������Ϊ�գ�Ĭ�Ͼ��ǻ����ַ���
*��Ŀ��	�ж��Ƿ��ǻ����ַ���
*����	�Ա������£�����������Ѿ��Ǻܺõķ����ˣ�Ч��Ҳ��
		���ǵ��˿յ��������Сд�����
		���ҿ��ǵ�������������������ո񰡣����Ű����ַ������

		�����ҿ������˵�˼·��򵥸Ľ���һ�£��������ò����¿��ٿռ��ˣ�һ�α���ȫ���㶨
***********************/

#pragma once
#include <string>

using namespace std;

class ValidPalindrome
{
public:
	ValidPalindrome();
	~ValidPalindrome();
	/********************
	*����:�������д�ķ��� ���ȴ������ȡ��ֻ����ĸ�����ֵ��ַ��� Ȼ���ǰ����Ƚϼ���
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:425�����Լ�12ms
	*����:
	********************/
	bool isPalindrome_Dwyer(string s) {
		//���ַ���
		if (s.empty()) return true;

		//�Ƚ�
		auto front = s.begin();
		auto back = s.end() - 1;
		while (front < back){
			//ǰ����Ч
			if (!isalnum(*front)) ++front;
			//������Ч
			else if (!isalnum(*back)) --back;
			//���ֲ����
			else if (!(tolower(*front) == tolower(*back)))
				return false;
			//��ȣ������Ƚ���һ��
			else{
				++front;
				--back;
			}
		}
		return true;
	}
};

