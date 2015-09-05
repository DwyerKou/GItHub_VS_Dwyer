/***********************
*Date:	2015.6.28
*Problems:	Given a collection of numbers, return all possible permutations.
		For example,
		[1,2,3] have the following permutations:
		[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*����:	���������Ŀ�����ٻ����n�Ľ׳˸��������ôʱ�临�ӶȾ�������O��n��n�η�����û������
*��Ŀ��	����һ���������飬�����������
*����	�������n�Ľ׳˵�Ч�ʿֲ�����
		��Ҫ�������˼Ҹ������͵Ĳ�������ʱ��������㷨��Ч�ʣ�������ε��Ҿ���Ҫ���Ͽ����µĿռ�
		������㷨ֱ����д�˺��������Զഫ����

		����һ����ǿ������˼���ǰ������㷨�ˣ�Ȼ����Ҫ��д�в�ͬ�����ĺ�������������㷨���˼ҾͲ�ͬ��
		�Ǿ����Ǳ��˼������ˣ������Լ����㷨���������ء����й�ϵ�ɣ�������
***********************/


#pragma once

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Permutations
{
public:
	/********************
	*����:�������д�ķ��������õݹ��˼·
	*ʱ�临�Ӷȣ�O(n��n�η�)
	*LeetCodeЧ��:25�����Լ�28ms
	*����:�����8�����ݿ����Ѿ�û������
			������ܴ�ǰ���󽻻�����vector��֧��push_front������ѡ���˴Ӻ���ǰ
	********************/
	vector<vector<int>> permute_Dwyer(vector<int>& nums){
		vector<vector<int>> result;
		vector<vector<int>> newResult;//���ȥ�����һ��Ԫ�ص����е�����
		vector<int> newNums;//���ȥ�����һ��Ԫ�ص�nums
		if (!nums.empty()){
			vector<int>::iterator back = nums.end() - 1;
			vector<int>::iterator front = nums.begin();
			vector<vector<int>>::iterator nbegin;
			//���α�����ǰ�����е������һ�����ֵ���λ��
			while (front != nums.end()){
				swap(*front, *back);//����
				//��ʵ��������ǽ�������
				if (nums.size() == 1)
					result.push_back(nums);
				else{
					newNums.assign(nums.begin(), nums.end() - 1);
					//�ݹ飬�����һ��ǰ�����еĽ������У��õ�newResult
					newResult = permute(newNums);
					newNums.clear();
					nbegin = newResult.begin();
					//����newResult��Ȼ��������һ��Ԫ�ؼ���
					while (nbegin != newResult.end()){
						newNums.assign((*nbegin).begin(), (*nbegin).end());
						newNums.push_back(*back);
						result.push_back(newNums);
						newNums.clear();
						++nbegin;
					}
				}
				swap(*front, *back);//��������
				++front;
			}
		}
		return result;
	}


	/********************
	*����:�������������ͶƱ���㷨
	*ʱ�临�Ӷȣ�O(n��n�η�)
	*LeetCodeЧ��:25�����Լ�12ms
	*����:�����8������Ҳ��Ҫͦ�ã����Ǳ���д�Ļ���Ҫ��
	*���򣺻���˼·���ҵ���һ�µģ����Ĵ�����ҵľ������֮�࣬�ܴ�̶�������Ϊ�����ϵĽ�����ֵ��Ȼ�����
			��û�п����µĿռ䣬�������Ŀ�����Ը������һЩ
			����һ���޴�Ĳ���ǣ���ÿ�ε��õĶ���ֻ��һ��������vector<int>& nums��û���洢��ǰ�û��������ˣ�����ֻ��
			����һ���µ�newNums������Ŀ�ͷ���൱��begin���Ƶġ�������д��һ����������һ������begin���������ò��ſ����¿ռ���
	********************/
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		//�Լ��¸�ú������õ�����Ԫ�ؿ�ʼ������
		permute(ans, nums, 0);
		return ans;
	}

	void permute(vector<vector<int>>& ans, vector<int>& perm, int begin)
	{
		//��������
		if (begin == perm.size()) {
			ans.push_back(perm);
			return;
		}
		//i��begin��ʼ����
		for (int i = begin; i<perm.size(); i++) {
			//������ֺ�begin����λ�õ�ֵ��ȵ�Ԫ�أ������������´�ѭ��
			//if (i != begin && perm[i] == perm[begin]) continue;
			//����i��beginλ�õ�ֵ
			swap(perm[i], perm[begin]);
			//�ó�����Ԫ�غ��begin+1λ�õ�����
			permute(ans, perm, begin + 1);
			//��λ�õ�������
			swap(perm[i], perm[begin]);
		}

	}
};

