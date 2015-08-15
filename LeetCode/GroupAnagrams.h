/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/
#pragma once
#include "LeetCode.h"
class GroupAnagrams
{
public:
	GroupAnagrams();
	~GroupAnagrams();
	/*
	ֻ��һ��һ�±����� nƽ���ĸ��Ӷ�
	��map
	�������ͨ���ˣ�Ȼ������ô�ĳ�ʱ�ˣ���������������������
	*/
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> re;
		vector<int> v(strs.size(), 0);//�����0˵����û�ҵ���֯�������1ֱ������
		int n = strs.size();
		if (n == 0) return re;
		int index = -1;
		for (size_t i = 0;i < n&&v[i] == 0;i++) {
			re.push_back(vector<string>{strs[i]});
			index++;
			v[i] = 1;
			unordered_map<char,int> m;
			for (auto c : strs[i])
				m[c]++;
			unordered_map<char, int> m_backup = m;
			for (size_t j = i+1;j < n&&v[j] == 0;++j) {
				for (auto ch : strs[j])
					--m[ch];
				auto it = m.begin();
				while (it != m.end()){
					if (it->second != 0) 
						break; 
					++it;
				}
				if (it != m.end()) continue;
				re[index].push_back(strs[j]);
				v[j] = 1;
				m = m_backup;
			}
		}
		//ȫ�������Ժ�Ҫ��������
		auto b = re.begin();
		while (b != re.end()) {
			sort((*b).begin(), (*b).end());
			++b;
		}
		return re;
	}

	/*
	�·��� ����map�� ֱ�ӵ���stl
	��strs�е�ÿһ��string���������� ��������
	76ms
	*/
	vector<vector<string>> groupAnagrams2(vector<string>& strs) {
		vector<vector<string>> result;
		vector<string> sortedStrs = strs;
		unordered_map<string, vector<int>> map;
		for (int i = 0; i < strs.size(); i++) {
			sort(sortedStrs[i].begin(), sortedStrs[i].end());//��ÿһ��string����
			map[sortedStrs[i]].push_back(i);//Ȼ��Ž�һ��map
		}
		int index = -1;
		for (auto it = map.begin(); it != map.end(); it++) {
			result.push_back(vector<string>{});
			index++;
			for (int i = 0; i < it->second.size(); i++) {
				result[index].push_back(strs[it->second[i]]);
			}
		}
		auto b = result.begin();
		while (b != result.end()) {
			sort((*b).begin(), (*b).end());
			++b;
		}
		return result;
	}
};

