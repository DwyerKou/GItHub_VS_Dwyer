/***********************
*Date:	2015.7.16
*Problems:	Determine whether an integer is a palindrome. Do this without extra space.
*����:
*��Ŀ��
*����	�ҵĺܿ� ��c++��ǰ�� 76ms �����¶���������int�� ���������� �����Ľ�
***********************/
#pragma once
//log10�Լ�floor����amp-Math��
#include <amp_math.h>
class PalindromeNumber
{
public:
	PalindromeNumber();
	~PalindromeNumber();
	/********************
	*����:���˵ķ��������٣���һ���ռ䣬��������֮������ֻ����һ���ͣ���ж��Ƿ������
	*LeetCodeЧ��:80ms
	********************/
	bool isPalindrome1(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		int y = 0;
		while (y < x){
			y = y * 10 + (x % 10);
			x /= 10;
		}
		return (y == x) || (y / 10 == x);
	}

	/********************
	*����:	���˵ķ���������������û�п����µĿռ�
			�ر�֮���������������log�Լ�pow�Ӷ��õ�ͷ��β
			��Ҫ���ǵ���;����0�����
	*LeetCodeЧ��:80ms
	********************/
	bool isPalindrome2(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		while (x){
			//ֻҪС��10�ˣ��Ϳ��Խ�����
			if (x / 10 == 0) return true;
			//x / (pow10(size(x)))��ͷ   x % 10��β
			if (x / (pow10(size(x))) != x % 10) return false;
			//pow10(zerosAfterHead(x) + 1�������ж���0Ȼ��+1��x % pow10(zerosAfterHead(x) + 1)����׼ȷȡ�����׵�0��ʣ�µ�
			//����պ�ʣ1λ���Ǿͼ����´�ѭ�������ʣ��λ���Ǿ�����
			if ((x % pow10(zerosAfterHead(x) + 1)) / 10 > 0) return false;

			//ȥβ��ʱ��Ҫ����βǰ��0��λ��ȥ����֤һ�ΰ�0ȥ�ɾ�
			x = x / pow10(zerosAfterHead(x) + 1);
			//ȥͷ��ʱ��
			x = x % (pow10(size(x)));
		}
		return true;
	}

private:
	int pow10(int x){
		return pow(10, x);
	}
	int size(int x){
		//floor��ȡ����
		//log10��ȡlog
		return (int)floor(log10(x));
	}
	int zerosAfterHead(int x){
		return size(x) - size(x % (pow10(size(x)))) - 1;
	}
};

