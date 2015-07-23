/*
	Count the number of prime numbers less than a non-negative number, n.
	�����õ�һ������Sieve of Eratosthenes ��˼��
	���Ǳ���2����������ô4��6��8��10���Ǻ���
	Ȼ��3��������9��12��15��18���Ǻ���
	7������ 49��56.�����Ǻ���
	
*/
#pragma once
#include <vector>
using namespace std;
class CountPrimes
{
public:
	CountPrimes();
	~CountPrimes();
	int countPrimes(int n) {
		if (n < 2) return 0;
		vector<bool> v(n, true);
		for (size_t i = 2; i <= sqrt(n); ++i){//ֻ�ÿ���n�Ŀ�ƽ���Ϳ����ˣ���
			if (v[i]){
				for (size_t j = i*i; j < n; j+=i){//����ÿ��j����i��ƽ����ʼ����Ϊ����i=5����10��15��20��������ڴ���2��3��4��ʱ��㶨��
					if (v[j])
						v[j] = false;
				}
			}
		}
		int count = 0;
		for (size_t i = 2; i < v.size(); ++i){
			if (v[i])
				count++;
		}
		return count;
	}
};

