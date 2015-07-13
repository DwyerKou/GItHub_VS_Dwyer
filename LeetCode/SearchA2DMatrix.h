/***********************
*Date:	2015.7.11
*Problems:	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*����:	��ά���飬�������ȱ���ÿ�������ͷ��Ȼ���ҵ���һ��ͷ���ֱ�target��ĵ�ǰһ�У�Ȼ��������ڵ���һ�У���Ϊ�Ѿ��ź����ˣ����Զ���
		��ǰ�������������
*��Ŀ��	����һ���й��ɵ����飬����ĳ��ֵ
*����	binary_search��findҪ�죡����������������
		��ϸ���룬���������ʵľ��Ƕ�������������Ϊ�Ǵ�С��������ģ���Ҫ�ȱ����죡��
		��������ͨ�ı���Ҳ��findҪ�죡������������������������
		��ģ������ⶼ����û�˽���������ر�֮�����д�������ô���õı�������
***********************/
#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class SearchA2DMatrix
{
public:
	SearchA2DMatrix();
	~SearchA2DMatrix();
	/********************
	*����:�������д�ķ��� �������ȸ���ÿһ�еĵ�һ�������ҵ�Ѱ��target����һ�У�Ȼ�����find�㷨��3
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:16ms
	********************/
	bool searchMatrix_Dwyer(vector<vector<int>>& matrix, int target) {
		vector<vector<int>>::iterator row = matrix.begin();
		vector<vector<int>>::iterator front_row = row;
		if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[0][0] > target) return false;
		while (row != matrix.end()){
			if ((*row)[0] > target)
				break;
			front_row = row;
			++row;
		}
		if (find((*front_row).begin(), (*front_row).end(), target) != (*front_row).end())
			return true;
		return false;
	}

	/********************
	*����:�������д�ĵڶ������� �������ϵͳ�ṩ���㷨
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:ͬ����ʱ16ms
	********************/
	bool searchMatrix_Dwyer2(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size();i++)
			if (find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end())
				return true;
		return false;
	}

	/********************
	*����:�������д�ĵ��������� ����binary_search
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:�ĳ�binary_search ֻ��12ms�������㷨��ѡ��Ӱ��ͦ���
	********************/
	bool searchMatrix_Dwyer3(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size(); i++)
			if (binary_search(matrix[i].begin(), matrix[i].end(), target))
				return true;
		return false;
	}

	/********************
	*����:�������д�ĵ�һ=��������find��binary_search����
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:ͬ���ﵽ��12ms
	********************/
	bool searchMatrix_Dwyer4(vector<vector<int>>& matrix, int target) {
		vector<vector<int>>::iterator row = matrix.begin();
		vector<vector<int>>::iterator front_row = row;
		if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[0][0] > target) return false;
		while (row != matrix.end()){
			if ((*row)[0] > target)
				break;
			front_row = row;
			++row;
		}
		if (binary_search((*front_row).begin(), (*front_row).end(), target))
			return true;
		return false;
	}

	/********************
	*����:�������д�ĵ�һ��������find����ͨ�ı�������
	*ʱ�临�Ӷȣ�O(n)
	*LeetCodeЧ��:Ҳ������12ms����������������
	********************/
	bool searchMatrix_Dwyer5(vector<vector<int>>& matrix, int target) {
		vector<vector<int>>::iterator row = matrix.begin();
		vector<vector<int>>::iterator front_row = row;
		if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[0][0] > target) return false;
		while (row != matrix.end()){
			if ((*row)[0] > target)
				break;
			front_row = row;
			++row;
		}
		vector<int > ::iterator begin = (*front_row).begin();
		while (begin != (*front_row).end()){
			if (*begin == target)
				return true;
			++begin;
		}
		return false;
	}
};

