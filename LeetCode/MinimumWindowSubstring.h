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
*�·���:��������������һ���ɣ����ڴ����һ��˼·��
		��Ҫ��һ��map�洢t��ÿ���ַ��Լ����ַ������˼���
		Ȼ����Ҫһ��map m_s��Ŀǰs�ߵ���λ�ó�����t�е��ַ�����
		ÿ��s�е�ÿ���ַ���������t��ÿ���ַ���������ͬ����Ҫ���¼�����롣�������ܼ򵥣���һ��front��ֻ�������ߣ��ߵ���һ��t�г��ֵ��ַ��Ϳ�ʼ��front��tail�ľ���
		ÿ�μ��������󣬾Ͱ�frontָ������ַ���m_s���Ƴ�������������s
		��Կ����е�'bba'\'ba'�����������ÿ���˵Ĵ��붼��һ��charCounter��ֻ�е�Ŀǰm_s������ʵʵ���ܹ���֤t�е��ַ���������ͬ�����������ֵ�Ż���Ϊt.size()

		�����Ϳ�minWindow_Dwyer3�������������
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

	/********************
	*����:�������д�ĵڶ����������Ѿ�ͨ���ˣ����ǳ�ʱ
	*ʱ�临�Ӷȣ�
	*LeetCodeЧ������ʱ
	********************/
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

	/********************
	*����:�������д�ĵ���������������discuss�Ժ�д��
	��Ҫ��ͬ�ǣ���������ÿ��λ�ö���ֵ�����ǿ������Ƿ�ﵽ��T���ַ�������
	���ԣ��ұ��˼Ҳ����û���ҵ�һ���õķ���ȥ�жϺ�ʱ�����ƶ�front��back��ʱ��
	��ԭ��map�д����λ�ã��˼Ҵ������������ʵ���룬û��Ҫ��λ�õģ���Ϊ�Ѿ���front��back��
	*ʱ�临�Ӷȣ�
	*LeetCodeЧ����152ms��cpp������������
	*����	����㷨ʵ��ֵ�úúÿ�������Щ�ط���ȷ���㲻���뵽��
	********************/
	string minWindow_Dwyer3(string s, string t) {
		int front = 0;
		int length = INT_MAX;
		int charCounter = 0;
		string result;
		unordered_map<char, int> m;//�洢������t�е�ÿ���ַ���λ�� char���ַ���int������
		unordered_map<char, int> w;//��s����t�д��ڵ��ַ���char���ַ���int������������ÿ��w��ÿ���ַ������������ڵ���m����ô���ھ��Ǽ��㴰�ڵ�ʱ��

		if (t.empty()) return result;

		for (auto c : t)
			++m[c];

		for (int i = 0; i < s.size(); ++i) {
			if (m.find(s[i]) != m.end()){
				//ֻҪ����t����w���
				++w[s[i]];
				//����ֻ�е�w������ַ�����m����ʱ����++charCounter
				//�������Է�ֹs=��bba����t=��ba�������
				if (w[s[i]] <= m[s[i]])
					++charCounter;
			}
			if (charCounter == t.size()){
				//���while����Ҫ������
				//���front��ǰָ���ַ�����t�У�ֱ������
				//��һ��t�У����ñ�֤��'bba'/'ba'��������£�frontָ��ڶ���b�����Ե�w[s[front]]>m[s[i]]��������ǣ���Ҫ��--w[s[front]]ͬʱ����front
				while (front<s.size() && ((m.find(s[front]) != m.end() && w[s[front]]>m[s[front]])) || m.find(s[front]) == m.end()){
					if (m.find(s[front]) != m.end())
						--w[s[front]];
					++front;
				}
				if (length > (i - front + 1)){
					length = i - front + 1;
					result = s.substr(front, length);
				}
				--charCounter;
				--w[s[front]];
				++front;
			}
		}
		return result;
	}


	/********************
	*����:���������Ч����ߵ�һ��
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ����12ms ��������
	*����	��������������ˣ�Ȼ��ʵ��û��ʲô���⣬������152ms���㷨û��ʲô˼���ϵĲ��֮�����ܹ�����12ms����������Ϊ���������
			�����飬��������c�ķ��룬������������ԭ���
	********************/
	std::string minWindow(std::string s, std::string t)
	{
		//��Ϊascii���֧��128���ַ�
		const size_t kCHARLEN = 128;

		int char_counts[kCHARLEN] = { 0 };

		//
		int unique_counts[kCHARLEN] = { 0 }; // use to judge if t contains char x in complexity O(1)

		size_t need_reduced_count = 0; // count of unique char in t

		// init
		for (std::string::iterator iter = t.begin();
			iter != t.end(); ++iter) {
			if (++unique_counts[*iter] == 1) {//��t�е��ַ���������unique_counts��Ӧ���±ֵ꣬��������ֳ��ֵĴ���
				++need_reduced_count;//��t���ж��ٸ��������ַ�
			}
			++char_counts[*iter];//��t�е��ַ���������char_counts��Ӧ���±ֵ꣬��������ֳ��ֵĴ���
		}

		size_t min_head = 0;
		size_t min_len = 0;

		// loop
		for (size_t head_pos = 0, tail_pos = 0; tail_pos < s.size(); ++tail_pos) {

			char tail = s[tail_pos];//�����ַ�

			// tail in t && fully contained in sub
			//�������ַ���t���в��Ҹպ�ֻ������һ�Σ���need_reduced_count--
			//ͬʱchar_countsҲ��--��0�˲Ż�need_reduced_count
			if (unique_counts[tail] > 0 && --char_counts[tail] == 0)
				--need_reduced_count;

			//ֻҪneed_reduced_count����Ϊ0��˵�������ַ�û�ҵ���ֱ�Ӽ���ѭ��
			if (need_reduced_count != 0)
				continue;

			//��������ܹ��ߵ����˵����ǰt�����е��ַ��Ѿ����ֹ�һ����
			//Ŀǰ��״̬�ǣ�need_reduced_count�պõ���0�ˣ�unique_countsʼ���Ƕ�t��ֱ�۱�ʾ�������б仯
			//char_counts
			// reach a window

			bool is_window = true;//���˸���־λ
			while (is_window && head_pos <= tail_pos) {//ͷ��βǰ ���ѭ�����ں���ͷ
				char head = s[head_pos];//ͷ��ָ���ַ�
				// head in t
				if (unique_counts[head] > 0) {//������ַ���t��
					++char_counts[head];//char_counts����ַ�+1
					// gonna break a window
					if (char_counts[head] > 0) {//���>0
						++need_reduced_count;//need_reduced_count+1
						is_window = false;//����ѭ�������������Ҫ�����µľ��룬Ȼ�󻹵���head_pos��������һ�£�ͬʱneed_reduced_count�ü�һ�£���ʾ��ȱ��һ���ַ���
						//ͬʱchar_countsҲ�ü�һ�£��Ա�֪��ȱ���ĸ��ַ�
						// record min �������
						if (min_len == 0 || tail_pos - head_pos < min_len) {
							min_head = head_pos;
							min_len = tail_pos - head_pos + 1;
						}
					}
				}
				++head_pos;
			}
		}

		return s.substr(min_head, min_len);
	}
};