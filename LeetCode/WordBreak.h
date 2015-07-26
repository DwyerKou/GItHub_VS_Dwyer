/*
	Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

���������ٶ���ĳ��ֹ�
		���õ��Ƕ�̬�滮��˼��
		���ĳ��λ����ǰ�ǿ��дʵģ������λ�ô���һ��vector
		Ȼ��ÿ�¼�һ���ַ����ͱ���ǰ�����п��дʵ�λ�õ���λ���Ƿ�����д�
		������ԣ�����λ�ÿ��дʣ���һ���ַ�
		�����ԵĻ�����һ��
���ʣ�������λ�ÿ��дʣ��Ǵ�ĳ��λ�õ����λ�ÿ���
		ͬʱĳ��λ��ǰ��Ҳȫ������
*/
#pragma once
#include <string>
#include <unordered_set>
using namespace std;
class WordBreak
{
public:
	WordBreak();
	~WordBreak();
	/*
		12ms
	*/
	bool wordBreak_Dwyer(string s, unordered_set<string>& wordDict) {
		if (s.empty()) return false;
		vector<int> v;//���v�洢���п��Ա��зֵ�λ�ã�����10�����棬��ʾ10֮ǰ�Ĳ��ֿ��Ա��з�
		v.push_back(-1);
		for (size_t i = 0; i < s.size(); ++i){
			auto begin = v.begin();
			while (begin != v.end()){
				if (wordDict.find(s.substr((*begin) + 1, i - (*begin))) != wordDict.end()){
					v.push_back(i);
					break;
				}
				++begin;
			}
		}
		if (v.back() == s.size()-1) return true;
		return false;
	}
};

