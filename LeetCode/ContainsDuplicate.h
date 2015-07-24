/***********************
*Date:2015.7.22
*Problems:Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*��Ŀ�����������ж��Ƿ����ظ�
*����	���붼Ӧ����map
***********************/
#pragma once
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class ContainsDuplicate
{
public:
	ContainsDuplicate();
	~ContainsDuplicate();
	/*
	�ҵķ���
	�򵥵ĺ� 52ms
	*/
	bool containsDuplicate_Dwyer(vector<int>& nums) {
		unordered_map<int, int> m;
		for (size_t i = 0; i < nums.size(); i++){
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = i;
			else
				return true;
		}
		return false;
	}

	/*
	���˷�����ֱ�Ӵ���һ��set�У�Ȼ���жϴ�С��̫ţ��!!!!!!!!!
	�򵥵ĺ� 52ms
	*/
	bool containsDuplicate(vector<int>& nums) {
		return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}
};

