/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/
#pragma once
#include "LeetCode.h"
class CombinationSum
{
public:
	CombinationSum();
	~CombinationSum();
	/*
	���������Ƶ����⣬���Ǹ�����������1,2,5Ӳ�ң����10�ж����ַ�����
	һ��� 80ms��������Ϊ���õĵݹ鲢û�н�ϻ��ݵ�˼�룬���²����ڿ����µ�path�ռ�
	Ȼ����Ҫ�����Ľ��ɻ��ݵ�˼��
	�����Ժ�16ms
	*/
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> re;
		if (candidates.empty()) return re;
		vector<int> path;
		sort(candidates.begin(), candidates.end());//��ΪҪ����������ģ����Ի�����ǰ����
		combinationSum(re,candidates,path,0,target);
		return re;
	}
	void combinationSum(vector<vector<int>> &re, vector<int>& candidates, vector<int> &path,int index, int target) {
		if (!target) {
			re.push_back(path);//һ�����ϣ��������
			return;
		}
		//���Ի��ݷ���һ��Ҫ��֤��nums[0]�����п��ܶ������꣬Ȼ���nums[0]pop������������ȥ����nums[1]
		for (int i = index;i < candidates.size() && candidates[i] < target;++i) {
			path.push_back(candidates[i]);
			combinationSum(re, candidates, path, i, target-candidates[i]);//ע�����ﴫ�ݵ���i��������
			path.pop_back();//Ȼ������һ��pop����
		}
	}
};

