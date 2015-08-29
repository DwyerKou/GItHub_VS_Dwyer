/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
#pragma once
#include "LeetCode.h"
class GenerateParentheses
{
public:
	GenerateParentheses();
	~GenerateParentheses();
	/*
	*��ʵ�Ѿ�֪������ǿ����������ص�����ô���
	*��������1,1,2,5,14.������ ��Ҫ����֮ǰ�ļ�¼

	1. ÿ�ε�n�����¼���һ������
	2. ������ţ��������Ȱ�ס0�����ţ�ʣ��n-1��
	3. Ȼ���ס1�����ţ�ʣ��n-2�ԣ�Ȼ���ס2�ԣ�ʣ��n-3�ԡ�����������סn�ԣ�ʣ��0�ԣ�
	4. �����ǿ�������


	*/
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> backUp;
		if (n <= 0) return vector<string>{};
		if (n == 1) return vector<string>{"()"};

		backUp.push_back(vector<string>{""});
		backUp.push_back(vector<string>{"()"});
		for (size_t i = 2;i <= n;++i) {//�����ѭ����ÿ��ѭ����backUp�м������е�n�Ŀ��ܣ�������ȷ�ܺĿռ�
			vector<string> temp;
			for (size_t j = 0;j < i;j++) {//���µĵ�n�����ţ��ֱ��סj�����ŵ����������ô��ʣ����n-1-j�����������档ѭ����Ҫ��һ��������ϣ���j�����ŵĵ�ÿһ���������n-1-j��ÿһ�ֽ��һ��
				string tempStr = "(";
				for (int x = 0;x < backUp[j].size();x++) {
					string tempStrX = tempStr + backUp[j][x]+")";
					for (int y = 0;y < backUp[i - 1 - j].size();y++) {
						string tempStrY = tempStrX + backUp[i - 1 - j][y];
						temp.push_back(tempStrY);
					}
				}
			}
			backUp.push_back(temp);
		}
		return *backUp.rbegin();
	}
};

