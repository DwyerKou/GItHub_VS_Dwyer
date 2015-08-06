/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

�������n���ʺ����n*n�İ����ϣ������Լ��Խ��߲�����ײ
��������һ��Ӧ�÷�һ���ʺ�һ��Ҳֻ��һ��
���Կ��Բ������еķ�ʽ���ݹ�ʵ��
Ȼ���ж�ÿ�������Ƿ���Ϲ���
*/
#pragma once
#include "LeetCode.h"
class NQueensII
{
public:
	NQueensII();
	~NQueensII();
	/*
	�����½�һ����СΪn������v��Ȼ��v[i]��ֵ���ǵ�i�лʺ����ڵ��к�
	�ҿ�ʼ�ɵ�������v������һλ��0��n-1���������ǲ��Եģ�����������������������������
	���ĳ�������Ѿ����ֹ��ˣ���ôʣ�µ����־Ͳ�Ӧ���ٴγ��֣��������ܱ�֤����һ�У���������������������
	��һ��set����δ��д������
	8ms
	*/
	int totalNQueens(int n) {
		if (n < 1) return 0;
		if (n == 1) return 1;
		if (n < 4) return 0;
		vector<int> v(n, 0);
		int count = 0;
		int index = 0;
		vector<int> lastNums(n);
		while (n)
			lastNums[--n] = 1;
		n = v.size();
		totalNQueens(v, index, count, n, lastNums);
		return count;
	}
	/*
	index��v����Ӧ�����λ��
	count���ܵļ�����
	*/
	void totalNQueens(vector<int> &v, int& index, int& count, const int&n, vector<int> lastNums) {
		if (index == n) {
			if (judge(v, n))
				++count;
			--index;
			return;
		}
		else {
			for (size_t i = 0;i < n;++i) {
				if (lastNums[i]) {
					v[index] = i;
					if (!judge(v, index + 1)) //ǧ��ע�⣬������������ͳ�ʱ�ˣ�������������һ����ǰ��ֹ�ķ�����
						continue;
					lastNums[i] = 0;
					totalNQueens(v, ++index, count, n, lastNums);
					lastNums[i] = 1;
				}
			}
			--index;
			return;
		}
	}

	/*
	�ж��Ƿ����ԭ��
	v�е����ֲ����ڶԽ���
	*/
	bool judge(vector<int> &v, const int& n) {
		for (size_t i = 0;i < n - 1;++i)
			for (size_t j = i + 1;j < n;j++)
				if (abs(v[i] - v[j]) == (j - i))
					return false;
		return true;
	}
};

