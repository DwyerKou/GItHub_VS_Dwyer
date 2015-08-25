/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#pragma once
#include "LeetCode.h"
class LongestSubstringWithoutRepeatingCharacters
{
public:
	LongestSubstringWithoutRepeatingCharacters();
	~LongestSubstringWithoutRepeatingCharacters();
	/*
	��ȻҪ��ǰ�������
	������ö��м򵥱���(�ðɣ�����Ƿ��ȫ����������)
	�㶨��һ�����112ms��������
	����֮�ؾ����ҵ�smallerIndex ���԰���ά��map
	��ɵ���ˣ�����mapȥ��char�ˣ��Ҳ�����int������ô��ô�������Ӱ�������

	����int����map��������������16ms����켶��
	*/
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0, nowLen = 0, n = s.size();
		int smallerIndex = INT_MIN;//�����־�ر���Ҫ������value����С�ļ������Ҳ��Ϊ������
		int m[256];
		for (int i = 0;i < 256;i++)
			m[i] = -1;
		for (size_t i = 0;i < n;i++) {
			if (m[s[i]] == -1 || m[s[i]] < smallerIndex) {
				nowLen++;
				m[s[i]] = i;
			}
			else {
				if (maxLen < nowLen) maxLen = nowLen;
				smallerIndex = m[s[i]];
				nowLen = i - m[s[i]];
				m[s[i]] = i;
			}
		}
		if (maxLen < nowLen) maxLen = nowLen;
		return maxLen;
	}
};