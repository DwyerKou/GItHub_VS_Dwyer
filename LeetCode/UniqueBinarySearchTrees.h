/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/
#pragma once
#include "LeetCode.h"
class UniqueBinarySearchTrees
{
public:
	UniqueBinarySearchTrees();
	~UniqueBinarySearchTrees();
	/*
	������ö�̬�滮 ��Ҫ�õݹ�
	���������Ĺ��ɾ���numTrees(n)=numTrees(n-1)+numTrees(n-1)+numTrees(n-2)+...+numTrees(1)
	��һ��numTrees��n-1���ǰ�n����root������������ڶ���numTrees��n-1����n����n-1�ұߵ��������
	numTrees��n-2����n����n-2�ұߵ��������
	*/
	int numTrees(int n) {
		if (n == 0) return 1;
		if (n == 1) return 1;
		vector<int> v(n,0);
		v[0] = 1;
		for (int i = 1; i < n; i++){
			v[i] += v[i - 1];
			for (int j = i-1; j >= 0; j--){
				v[i] += v[j];
			}
		}
		return v[n - 1];
	}
};

