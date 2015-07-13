/***********************
*Date:2015.7.11
*Problems:Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*����	���ȹ̶�x,ֻ��y��Ȼ��̶�y��ֻ��x��Ȼ��̶�x��ֻ��y��Ȼ��̶�y��ֻ��x����������
ÿ�α䰴������Ĺ���
����n->(n-1)����->(n-2)����->...->1���ν���
		����������˿��������ܲ�����⣬��ʱ�临�Ӷȵ�ȷ����ˣ�Ҳû�п����˵Ĵ��룬��Ϊ���ö�ͦ���ӵ�
***********************/
#include <vector>
using namespace std;
#pragma once
class SpiralMatrixII
{
public:
	SpiralMatrixII();
	~SpiralMatrixII();

	/********************
	*����:�������д�ķ�����Ȼ��ʵ�ڲ���ʲô�÷�������Ҫ�õ������ı�־λ���ڱ�־��ʱ�仯k��ֵ����ʱ�仯Ӧ�üӻ��Ǽ�
	*ʱ�临�Ӷȣ�O(n��ƽ��)
	*LeetCodeЧ��:21�����Լ�4ms�������ǰ��λ��
	********************/
	vector<vector<int>> generateMatrix_Dwyer(int n) {
		//��ʼ��vector
		vector<vector<int>> v(n, vector<int>(n,0));

		int x = 0, y = 0;//x,y���������е��±�

		int j = 0, k = n;;//j����Ϊk������ÿ�θ㹻k���Ͱ�j��Ϊ0

		int flag_twice_k = 1,flag_twice_plus = 0;//flag_twice_kÿ�δﵽ2��k�ͼ�1;flag_twice_plusÿ�ε�2���ӱ���������

		bool flag_x = false;//countÿ�仯һ�Σ�flag_x�ͱ仯һ�Σ�trueʱ�仯x��falseʱ�仯y
		bool flag_plus = true;//true ��ʾҪ++��false��ʾҪ--��countÿ��countÿ��Ϊ1��ʱ��仯ֵ

		for (size_t i = 0; i < n*n; i++)
		{
			//�������ʼ��v�Ļ����������ᱨ��
			v[x][y] = i + 1;
			++j;

			//���Ĵ��룬�Ա���λ�Ŀ���
			if (j == k){
				j = 0; 
				flag_x = !flag_x;
				++flag_twice_k;
				++flag_twice_plus;
				if (flag_twice_k == 2){
					--k;
					flag_twice_k = 0;
				}
				if (flag_twice_plus == 2){
					flag_plus = !flag_plus;
					flag_twice_plus = 0;
				}
			}

			if (flag_x && flag_plus) ++x;
			if (flag_x && !flag_plus)--x;
			if (!flag_x && flag_plus) ++y; 
			if (!flag_x && !flag_plus) --y;
		}
		return v;
	}
};

