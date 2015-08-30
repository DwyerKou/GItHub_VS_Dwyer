/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]
*/
#pragma once
#include "LeetCode.h" 
class PalindromePartitioning
{
public:
	/*
	����������˵ݹ飬������һ��map�в��ϵı����Ž��
	�ҵķ������Ա������ݹ飬�����ǻ��ݷ��������������ҵķ�����Ҫ�����Ŀռ䱣���Ѿ�ͳ�Ƴ������ַ���
	����ʱ��Ƚ���
	���滹���������ݷ�
	*/
	vector<vector<string>> partition(string s) {
		if (s.empty()) return vector<vector<string>>{};
		unordered_map<int, vector<deque<string>>> m;
		vector<deque<string>> re = partition(s, 0, m);
		vector<vector<string>> reV;
		for (int i = 0;i < re.size();i++) {
			vector<string> temp;
			for (int j = 0;j < re[i].size();++j)
				temp.push_back(re[i][j]);
			reV.push_back(temp);
		}
		return  reV;
	}
	vector<deque<string>> partition(string &s, int index, unordered_map<int, vector<deque<string>>> &m) {
		vector<deque<string>> re;
		if (index == s.size() - 1) {
			vector<deque<string>> temp{ { s.substr(index,1) } };
			return temp;
		}if (index == s.size())
			return vector<deque<string>>{};
		int indexBack = index;
		while (index < s.size()) {
			if (palindrome(s, indexBack, index)) {//�������ʼλ�ã���indexλ���ǻ��ĵĻ�
				vector<deque<string>> temp;//temp�����Ŵ棨index+1����ĩβ�����л��Ľ��
				if (m.find(index + 1) == m.end()) {
					temp = partition(s, index + 1, m);
					m[index + 1] = temp;
				}
				else
					temp = m[index + 1];
				for (int i = 0;i < temp.size();++i) {
					temp[i].push_front(s.substr(indexBack, index - indexBack + 1));
					re.push_back(temp[i]);
				}if (temp.empty())
					re.push_back(deque<string>{s.substr(indexBack, index - indexBack + 1)});
				index++;
			}
			else//������ǻ��ģ���������ң�֪���ҵ�s�ĵ����ڶ�������
				index++;
		}
		return re;
	}

	//�жϴ�begin��end�ǲ��ǻ���
	bool palindrome(string& s, int begin, int end) {
		if (end == begin) return true;
		while (begin < end)
			if (s[begin++] != s[end--])
				return false;
		return true;
	}


	/*
	�������Ļ��ݷ�
	12ms
	*/
	vector<vector<string>> partition_Dwyer(string s) {
		vector<vector<string> > ret;
		if (s.empty()) return ret;

		vector<string> path;//path���ÿ�εõ���·������������
		dfs(0, s, path, ret);

		return ret;
	}
	void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
		if (index == s.size()) {
			ret.push_back(path);
			return;
		}
		for (int i = index; i < s.size(); ++i) {
			if (palindrome(s, index, i)) {//�����index��i�ǻ��ģ�������ǣ�һֱ++i���ҵ�����Ϊֹ�����֪�����û���ҵ����ģ�ʲôҲ����
				path.push_back(s.substr(index, i - index + 1));//���ⲿ�ֻ��Ĳ���path
				dfs(i + 1, s, path, ret);//Ȼ�����������
				path.pop_back();//Ȼ���path���ⲿ���ó���������i++
			}
		}
	}
};

