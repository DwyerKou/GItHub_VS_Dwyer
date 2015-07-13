/***********************
*Date:	2015.7.12
*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*����:	������һ��map����T��ÿ���ַ���λ�ã�ÿ�θ��£�������һ������t����С���䣨int��int������һ����ά�����ڣ����������ڶ�ά�����о���
��С���Ǹ������������յ�
*����	��������˺ܾã��о��Լ�д��������ˣ�����Ӧ��������ֽ�ʿ�������Լ���˼·��Ȼ���ٶ���
***********************/
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class MinimumWindowSubstring
{
public:
	MinimumWindowSubstring();
	~MinimumWindowSubstring();
	/********************
	*����:�������д�ķ�����û��ͨ����ԭ����û���ǵ�t�г����ظ�char�Ŀ���
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:��Լͨ����һ�룬100��������ǵ�t�г����ظ��ַ�ʱ��û��ͨ����
	********************/
	string minWindow_Dwyer(string s, string t) {
		int front = -1, back = -1;
		unordered_map<int, int> m;//�洢������t�е�ÿ���ַ���λ�� ��һ��int��t���ַ���λ�ã��ڶ�����s�����µ�λ��
		int pos = 0;//��ǰ��������s���ĸ�λ��

		//��ʼ����s
		for (char c : s){
			if (t.find(c) != string::npos){//����ַ�������t��
				m[t.find(c)] = pos;
				if (m.size() == t.size()){//���t�е�ÿ��char���Ѿ������ҵ���һ����
					vector<int> vt;
					for (auto pair : m){
						vt.push_back(pair.second);
					}
					sort(vt.begin(), vt.end());
					if (back == -1) {
						front = vt[0];
						back = *(vt.end() - 1);
					}
					else{
						int newdistance = *(vt.end() - 1) - vt[0];
						if (newdistance < (back - front)){
							front = vt[0];
							back = *(vt.end() - 1);
						}
					}
				}
			}
			++pos;
		}
		if (back == -1) return "";
		return s.substr(front, (back - front) + 1);
	}


	string minWindow_Dwyer2(string s, string t) {
		int front = -1, back = -1;
		unordered_map<int, int> m;//�洢������t�е�ÿ���ַ���λ�� ��һ��int��t���ַ���λ�ã��ڶ�����s�����µ�λ��

		for (int pos_s = 0; pos_s < s.size(); ++pos_s)
		{
			if (m.size() != t.size()){
				auto pos_t = t.find(s[pos_s]);
				int k = 0;
				string t_copy(t);
				while (pos_t != string::npos)
				{
					if (m.find(pos_t + k) == m.end())
					{
						m[pos_t + k] = pos_s;
						break;
					}
					else
					{
						t_copy.erase(pos_t, 1);
						++k;
						pos_t = t_copy.find(s[pos_s]);
					}
				}
				if (m.size() == t.size()){
					vector<int> vt;
					for (auto pair : m){
						vt.push_back(pair.second);
					}
					sort(vt.begin(), vt.end());
					front = vt[0];
					back = *(vt.end() - 1);
				}
			}
			else
			{
				//�ҵ����ַ���t�е�����λ�ã�Ȼ��ѡ����С���Ǹ������滻����
				vector<int> v;//v�д�����е�λ��
				auto pos_t = t.find(s[pos_s]);
				int k = 0;
				string t_copy(t);
				while (pos_t != string::npos)
				{
					v.push_back(pos_t + k);
					t_copy.erase(pos_t, 1);
					++k;
					pos_t = t_copy.find(s[pos_s]);
				}

				//v�д����m���±꣬�ҵ���С�ĺ��滻֮
				if (!v.empty()){
					int j = m[v[0]];
					int temp = 0;
					for (auto vc : v){
						if (j > (m[vc])){
							j = m[vc];
							temp = vc;
						}
					}
					m[temp] = v[temp];

					vector<int> vt;
					for (auto pair : m){
						vt.push_back(pair.second);
					}
					sort(vt.begin(), vt.end());
					int newdistance = *(vt.end() - 1) - vt[0];
					if (newdistance < (back - front)){
						front = vt[0];
						back = *(vt.end() - 1);
					}
				}
			}
		}
		if (back == -1) return "";
		return s.substr(front, (back - front) + 1);
	}
};