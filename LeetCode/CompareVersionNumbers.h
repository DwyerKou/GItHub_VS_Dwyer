/***********************
*Date:2015.7.14
*Problems:Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*��Ŀ���Ƚϰ汾
*����	�ݣ��������Ⱑ��һ��easy���⻨������һ��Сʱ��������
		Ҫ���ǵ�1/1.0ĩβΪ0��������Լ�һ����һ���̵������
***********************/
#pragma once
#include <string>
using namespace std;
class CompareVersionNumbers
{
public:
	CompareVersionNumbers();
	~CompareVersionNumbers();
	/********************
	*����:�������д�ķ���
	*LeetCodeЧ��:0ms
	*����:�Լ�д���㷨LOW���ˣ���Ȼһ��һ�±Ƚϸ��ֿ��ܵ����
	********************/
	int compareVersion_Dwyer(string version1, string version2) {
		while (!version1.empty() && !version2.empty()){
			auto p1 = version1.find('.');
			auto p2 = version2.find('.');
			if (p1 == string::npos&&p2 != string::npos){
				if (atoi(version1.c_str()) > atoi(version2.substr(0, p2).c_str())) return 1;
				if (atoi(version1.c_str()) < atoi(version2.substr(0, p2).c_str())) return -1;
				//��ֹ1��1.0�Ŀ���
				if (atoi(version1.c_str()) == atoi(version2.substr(0, p2).c_str())){
					version2.erase(0, p2 + 1);
					if (atoi(version2.c_str()) == 0) return 0;
					else return -1;
				}
			}
			if (p1 != string::npos&&p2 == string::npos){
				if (atoi(version2.c_str()) > atoi(version1.substr(0, p2).c_str())) return -1;
				if (atoi(version2.c_str()) < atoi(version1.substr(0, p2).c_str())) return 1;
				//��ֹ1��1.0�Ŀ���
				if (atoi(version2.c_str()) == atoi(version1.substr(0, p1).c_str())){
					version1.erase(0, p1 + 1);
					if (atoi(version1.c_str()) == 0) return 0;
					else return 1;
				}
			}
			if (p1 == string::npos&&p2 == string::npos){
				if (atoi(version2.c_str()) > atoi(version1.c_str())) return -1;
				if (atoi(version2.c_str()) < atoi(version1.c_str())) return 1;
				if (atoi(version2.c_str()) == atoi(version1.c_str())) return 0;
			}
			if (version1.substr(0, p1) == version2.substr(0, p2)){
				version1.erase(0, p1 + 1);
				version2.erase(0, p2 + 1);
				continue;
			}
			if (atoi(version1.substr(0, p1).c_str()) > atoi(version2.substr(0, p2).c_str())) return 1;
			if (atoi(version1.substr(0, p1).c_str()) < atoi(version2.substr(0, p2).c_str())) return -1;
			if (atoi(version1.substr(0, p1).c_str()) == atoi(version2.substr(0, p2).c_str())) return 0;
		}
		if (version1.empty() && version2.empty()) return 0;
		if (version1.empty()) return -1;
		if (version2.empty()) return 1;
	}


	/********************
	*����:����Ǳ��˵ķ���
	*LeetCodeЧ��:1ms
	*����:��ȡÿ��С����ǰ�����֣�һ���ַ�һ���ַ��Ĵ���ת��Ϊ10���ƣ�����������һ����һ�δ���һ��С������һ�Σ���ͻᵼ��
			��Ҫ�жϸ��ֿ��ܵ��������1.0/1��
			����С���㳤�Ȳ�ͬ��while (i<n1 || j<n2)һ��㶨!!!!!!!!!!!!!
	********************/
	int compareVersion(string version1, string version2) {
		int i = 0;
		int j = 0;
		int n1 = version1.size();
		int n2 = version2.size();

		int num1 = 0;
		int num2 = 0;
		while (i<n1 || j<n2)//�����������ﵽ��β�Ż��������Ч��ֹ1.1/1����� perfect!!!!!!!!
		{
			//ÿ��С��������ʮ���Ʊ�ʾ ��һ����һ���Ѿ��������Ͳ�����i<n1 ,numʼ��Ϊ0������������perfect
			while (i<n1 && version1[i] != '.'){
				num1 = num1 * 10 + (version1[i] - '0');
				i++;
			}

			while (j<n2 && version2[j] != '.'){
				num2 = num2 * 10 + (version2[j] - '0');;
				j++;
			}

			if (num1>num2) return 1;
			else if (num1 < num2) return -1;

			//��ԭ��ȥ
			num1 = 0;
			num2 = 0;
			//��i��j���С����
			i++;
			j++;
		}

		return 0;
	}
};

