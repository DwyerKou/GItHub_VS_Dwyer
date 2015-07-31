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
	
	��������Ǵ�ģ���������������������������������������
	���������Ĺ��ɾ���numTrees(n)=numTrees(n-1)+numTrees(n-1)+numTrees(n-2)+...+numTrees(1)
	��һ��numTrees��n-1���ǰ�n����root������������ڶ���numTrees��n-1����n����n-1�ұߵ��������
	numTrees��n-2����n����n-2�ұߵ��������


	���²�����ȷ�Ĺ���
	�������һ�����͵� ��������
	��n��ÿ���ڵ㶼��root��Ȼ������нڵ���root�ĺͼ�����
	����n=9��Ŀǰ��root��4������ô4��߻���1,2��3�����numTrees��3�� Ȼ��5,6,7,8,9�����ұ� �������ʵ�൱��numTrees��5��
	����h��n��=h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
	h(1)=1�������ʣ�����h��0��ֱ�۵����Ӧ����0������ʵ��Ӧ����Ϊ1.

	������ҹ��ƴ󲿷��˶��ǳ��ģ�����ʱ�䶼��0ms
	*/
	int numTrees(int n) {
		if (n == 0) return 1;
		if (n == 1) return 1;
		vector<int> v(n+1,0);
		v[0] = 1;
		v[1] = 1;
		for (int i = 2; i < n+1; i++){
			for (int j = 0; j < i; j++){
				v[i] += (v[j]*v[i-j-1]);
			}
		}
		return v[n];
	}
};

