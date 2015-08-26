/*
The set [1,2,3,��,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#pragma once
#include "LeetCode.h"
class PermutationSequence
{
public:
	PermutationSequence();
	~PermutationSequence();
	/*
	���ϸ���k�����������飬Ȼ��ÿ��ѭ������ȷ��һλ
	8ms
	���˺ܶ��Ź�ȥ

	*/
	string getPermutation(int n, int k) {
		string re;
		if (n < 1 || k < 1) return re;
		if (n == 1) return "1";
		vector<int> vJC = { 1 };//���1��n-1�Ľ׳�
		for (size_t i = 1;i < n - 1;i++)
			vJC.push_back((i + 1)*vJC[i - 1]);
		if (k > (*vJC.rbegin())*n) return re;
		vector<int> vNums(n);//���n������
		for (size_t i = 0;i < n;i++)
			vNums[i] = (i + 1);
		auto index = vJC.rbegin();//����ɺ���ǰ�����׳�
		while (index != vJC.rend()) {
			int index4Nums = (k - 1) / (*index);//�����±����
			re = re + char(vNums[index4Nums] + '0');
			auto it = find(vNums.begin(), vNums.end(), vNums[index4Nums]);
			vNums.erase(it);//����ǵ���8ms��ԭ��
			k = k % (*index);//�޸�k�ĺ��Ĵ���
			if (k == 0) k = *index;//����ǵ�����ô��ι���ȥ��ԭ�򣡣�����������
			index++;
		}
		re = re + char(vNums[0] + '0');
		return re;
	}
};

