/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
#pragma once
#include "LeetCode.h"
class PascalTriangleII
{
public:
	PascalTriangleII();
	~PascalTriangleII();
	/*
	0ms һ���
	vÿ���޸����������һ��1
	*/
	vector<int> getRow(int rowIndex) {
		//Ҫ�󿪱ٵĿռ���O(k)
		vector<int> v;
		v.push_back(1);
		if (rowIndex == 0)
			return v;
		for (size_t i = 1; i < rowIndex + 1; ++i){
			auto begin = v.begin();
			int old = *begin;
			//�����޸�v�ķ���
			while (++begin!= v.end()){
				int temp = *begin;
				*begin = old + *begin; //�޸�
				old = temp;				//old�����ϴ��޸�ǰ��ֵ
			}
			v.push_back(1);
		}
		return v;
	}

	/*
	���˱��˵ķ��ֿ��Ը���
	һ��Ҫ�Ӻ���ǰ��
	�������ᶪʧ�����ǵ�����
	*/
	vector<int> getRow_Bieren(int rowIndex) {
		vector<int> v(rowIndex+1,0);
		v[0] = 1;
		for (int i = 1; i < v.size()+1; ++i)
			for (int j = i; j >= 1; j--)
				v[j] = v[j] + v[j - 1];
		return v;
	}
};

