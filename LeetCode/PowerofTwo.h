#pragma once
//Given an integer, write a function to determine if it is a power of two.
//�ж��ǲ���2�Ĵη�
class PowerofTwo
{
public:
	PowerofTwo();
	~PowerofTwo();

	bool isPowerOfTwo(int n) {
		//����int����ֱ���������㣬����Ҫ����ת��Ϊ������ʲô��
		//n&n-1 ʼ����0�������2�Ĵη��Ļ�
		return (n>0 && ((n&(n - 1)) == 0));
	}
};

