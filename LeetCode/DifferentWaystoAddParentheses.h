/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
��ԭ����setʵ�ֵ�
��������Ҫ��ĳ���vector
һ��ͨ��
4ms
*/

#pragma once
#include "LeetCode.h"
class DifferentWaystoAddParentheses
{
public:
	//���´�������ͨ��set�Ѿ��ɹ��ܳ����ģ���������Ŀ��Ȼ����ͬ��ֵҲ����ӡ������
	DifferentWaystoAddParentheses();
	~DifferentWaystoAddParentheses();
	/*
	���Ǽ����������붼�ǺϷ���
	���費����ô������û�����
	Ϊ�˷�ֹ��ֵͬ����Ҫһ��set�洢���Ľ��
	˼·��
		���ѣ��ݹ�ÿ�����ŵ���ߺ��ұߣ��õ���ߺ��ұ����еĿ��ܣ�Ȼ���������������ϼ���
	*/ 
	struct pair {
		int begin;
		int end;
		pair(int a, int b) {
			begin = a;
			end = b;
		}
		//�����Ǹ��ѵ㣬Ӧ����a���ȵ�����±�a��a��ȵ�����±�b
		bool operator< (const pair& pair2) const {
			if (begin < pair2.begin)
				return true;
			if (begin == pair2.begin)
				if (end < pair2.end)
					return true;
			return false;
		}
	};
	
	vector<int> diffWaysToCompute(string input) {
		vector<int> re;
		set<int> reSet;
		if (input.size() == 0) return re;
		map<pair, set<int>> m;//���m������ÿ����ͬpair֮������п��ܵļ�����
		//��Ϊ���ǵ�������������ܲ�ֻ��һλ�ģ����������Ȱ�input��⿪�������������飬һ��������֣���һ����������
		//Ҫע����ɣ�inputNumsҪ��inputOpe��һλ��
		vector<int> inputNums;
		vector<char> inputOpe;
		readInput(input, inputNums, inputOpe);
		//����һ��set,set����
		pair p(0, inputNums.size() - 1);
		reSet = diffWaysToCompute(inputNums, inputOpe,p, m);
		re.insert(re.end(), reSet.begin(), reSet.end());
		return re;
	}

	set<int> diffWaysToCompute(const vector<int> &inputNums, const vector<char> &inputOpe, pair p, map<pair,set<int>>& m) {
		set<int> s;
		if (m.find(p) != m.end()) return m[p];//����Ѿ�������Ͳ����ٴμ�����
		if (p.begin == p.end) {//��������
			s.insert(inputNums[p.begin]);
			return s;
		}
		for (size_t i = p.begin;i < p.end;++i) {//����ÿ�������
			pair leftP(p.begin,i);
			set<int> left = diffWaysToCompute(inputNums, inputOpe, leftP, m);
			pair rightP(i+1,p.end);
			set<int> right = diffWaysToCompute(inputNums, inputOpe, rightP, m);
			//��ʼ������set
			set<int>::iterator itL, itR;
			switch (inputOpe[i])
			{
			case '+':
				itL = left.begin();
				while (itL != left.end()) {
					itR = right.begin();
					while (itR != right.end()) {
						s.insert((*itL) + (*itR));
						itR++;
					}
					itL++;
				}
				break;
			case '-':
				itL = left.begin();
				while (itL != left.end()) {
					itR = right.begin();
					while (itR != right.end()) {
						s.insert((*itL) - (*itR));
						itR++;
					}
					itL++;
				}
				break;
			case '*':
				itL = left.begin();
				while (itL != left.end()) {
					itR = right.begin();
					while (itR != right.end()) {
						s.insert((*itL) * (*itR));
						itR++;
					}
					itL++;
				}
				break;
			default:
				break;
			}
		}
		m[p] = s;
		return s;
	}

	//�����ǶԻ���set���ϴ���ı���
	/*
	//�����Ǹ���vector��
	vector<int> diffWaysToCompute(string input) {
		vector<int> re;
		if (input.size() == 0) return re;
		map<pair, vector<int>> m;//���m������ÿ����ͬpair֮������п��ܵļ�����
							  //��Ϊ���ǵ�������������ܲ�ֻ��һλ�ģ����������Ȱ�input��⿪�������������飬һ��������֣���һ����������
							  //Ҫע����ɣ�inputNumsҪ��inputOpe��һλ��
		vector<int> inputNums;
		vector<char> inputOpe;
		readInput(input, inputNums, inputOpe);
		//����һ��set,set����
		pair p(0, inputNums.size() - 1);
		re = diffWaysToCompute(inputNums, inputOpe, p, m);
		return re;
	}
	
	vector<int> diffWaysToCompute(const vector<int> &inputNums, const vector<char> &inputOpe, pair p, map<pair, vector<int>>& m) {
		vector<int> s;
		if (m.find(p) != m.end()) return m[p];//����Ѿ�������Ͳ����ٴμ�����
		if (p.begin == p.end) {//��������
			s.push_back(inputNums[p.begin]);
			return s;
		}
		for (size_t i = p.begin;i < p.end;++i) {//����ÿ�������
			pair leftP(p.begin, i);
			vector<int> left = diffWaysToCompute(inputNums, inputOpe, leftP, m);
			pair rightP(i + 1, p.end);
			vector<int> right = diffWaysToCompute(inputNums, inputOpe, rightP, m);
			//��ʼ������set
			vector<int>::iterator itL, itR;
			switch (inputOpe[i])
			{
			case '+':
				itL = left.begin();
				while (itL != left.end()) {
					itR = right.begin();
					while (itR != right.end()) {
						s.push_back((*itL) + (*itR));
						itR++;
					}
					itL++;
				}
				break;
			case '-':
				itL = left.begin();
				while (itL != left.end()) {
					itR = right.begin();
					while (itR != right.end()) {
						s.push_back((*itL) - (*itR));
						itR++;
					}
					itL++;
				}
				break;
			case '*':
				itL = left.begin();
				while (itL != left.end()) {
					itR = right.begin();
					while (itR != right.end()) {
						s.push_back((*itL) * (*itR));
						itR++;
					}
					itL++;
				}
				break;
			default:
				break;
			}
		}
		m[p] = s;
		return s;
	}*/
	//���������ǺϷ���
	void readInput(const string &input, vector<int> &inputNums, vector<char> &inputOpe) {
		auto it = input.begin();
		int temp = 0;
		while (it != input.end()) {
			if (*it != '*'&&*it != '+'&&*it != '-')
				temp = temp * 10 + (*it - '0');
			else {
				inputNums.push_back(temp);
				temp = 0;
				inputOpe.push_back(*it);
			}
			it++;
		}
		inputNums.push_back(temp);
	}
};

