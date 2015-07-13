/***********************
*Date:2015.6.28
*Problems:Given an array of integers and an integer k, find out whether there there are two distinct indices i 
	and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*��Ŀ������һ���������飬�ж��Ƿ����������ͬ�����֣����ǵ��±�������Ϊk
*����	�������nƽ���ǲ������ܵ�
		��ʱ���ǻ᲻���ú�C++������ߵ����⣬���Ǵ��㷨
		Ҳ��֪���ҹ�����Ҫ���������������������Ǵ��㷨����Ȼ���еĻ�����ˣ������ȷ�����ֲ�ͬ������
***********************/

#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
class ContainsDuplicateII
{
public:
	ContainsDuplicateII();
	~ContainsDuplicateII();
	
	/********************
	*����:�������д�ķ�������������˼·��Ҳ��������forѭ��
	*ʱ�临�Ӷȣ�O(nƽ��)
	*LeetCodeЧ��:17�����Լ�12ms
	*����:���˺ܾú� 10000������ֱ�ӹҵ���
	********************/
	bool containsNearbyDuplicate_Dwyer(vector<int>& nums, int k) {
		if (k > nums.size())
			k = nums.size();
		while (!nums.empty() && k > 0 && k <= nums.size()){
			vector<int>::iterator it1 = nums.begin();
			vector<int>::iterator it2 = it1;
			while (it1 != nums.end() - k + 1){
				while (it2 != it1 + k){
					++it2;
					if (*it1 == *it2)
						return true;
				}
				++it1;
				it2 = it1;
			}
			return false;
		}
		return false;
	}

	/********************
	*����:����ǿ����������
		����unordered_map������˼���ǰ��±굱��value����ֵ����key��Ҳ���Ƿ���һ��
		Ȼ�����map���պ���ʡ�����½�������ܵ��µĿռ临�Ӷȹ��������
	*����:����㷨�൱�죬10000������ַ���
	*LeetCodeЧ��:17�����Լ�52ms
	*ʱ�临�Ӷȣ�O(nƽ��)
	********************/
	bool containsNearbyDuplicate_Best(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (int i = 0; i<nums.size(); i++){
			//����m.find(nums[i]) != m.end() ���Ա�֤ÿ�β����ֵ����ǵ�һ�γ��֣�ֱ����ӵ�map
			//����ܵ�m[nums[i]] >= i - k���ͱ�ʾ���ֵ�����ǵڶ��γ�����,���������m[nums[i]]��������һ�γ��ֵ�nums[i]���ֵ
			//m[nums[i]]������i�������ͬ��ֵ���±꣬Ȼ��ȥ��֤����±���i�ľ������Ϊk����
			if (m.find(nums[i]) != m.end() && m[nums[i]] >= i - k)
				return true;
			m[nums[i]] = i;
		}
		return false;
	}

	/********************
	*����:����ǿ�������һ��˼·�����˺ܶ෺���㷨
		����˼·ÿ�α�������find����Ѱ���Ƿ�����ֵͬ����Χѭ����n�ʣ���Χ����find���������㷨��������ʵȡ����find������
		���ǲ����ף�find��ҲӦ�����ڱ���n��Ϊ��Ч�ʻ���ô�ߣ�
	*����:����㷨�൱�죬10000������ַ��ӣ���΢��һЩ
	*ʱ�临�Ӷȣ�O(nƽ��)
	*LeetCodeЧ��:17�����Լ�32ms
	********************/
	bool containsNearbyDuplicateII(vector<int>& nums, int k) {
		if (nums.empty() || k<1)
			return false;
		vector<int> temp = nums;
		//C++��׼�����򣬾������������������ڲ�֪����������10000�������ر�죬ע����������temp
		sort(temp.begin(), temp.end());
		cout << "�������" << endl;
		//unique�Ѳ��ظ��Ĵ�ǰ���󵥶���һ�������ز��ظ������һ��
		auto it = unique(temp.begin(), temp.end());
		//������ж��Ƿ�����û����ֵͬ
		if (it == temp.end())
			return false;

		//���ﲻ����temp�ˣ���Ϊ�����С�궪ʧ�ˣ�������
		for (auto it1 = nums.begin(); it1 != nums.end() - 1; ++it1){
			//Ѱ���Ƿ�����*it1��ͬ��ֵ
			auto it2 = find(it1 + 1, nums.end(), *it1);
			//����еĻ��ж�����С���it1�����Ƿ񲻳���K
			if (it2 != nums.end()){
				if (it2 - it1 <= k){
					return true;
				}
			}
		}
		return false;
	}
};

