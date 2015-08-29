/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#pragma once
#include "LeetCode.h"
class SearchinRotatedSortedArray
{
public:
	SearchinRotatedSortedArray();
	~SearchinRotatedSortedArray();
	/*
	������һ�ַ��������ҵ��Ǹ��յ㣬Ȼ�����Ǹ��յ㴦һ������
	4ms
	*/
	int search_two(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		if (nums.size() == 1)
			if (nums[0] == target) return 0;
			else return -1;
			int n = nums.size();
			int f = 0, b = n - 1;
			while (f < b) {
				int mid = (f + b) / 2;
				if (nums[mid]>nums[n - 1])
					f = mid + 1;
				else
					b = mid;
			}
			//indexָ�������Ǹ���
			int index = f == 0 ? n - 1 : f - 1;
			if (target <= nums[index] && target>nums[n - 1] || index == n - 1) {
				//ǰ�����
				f = 0;
				b = index;
			}
			else {
				//����
				f = index + 1;
				b = n - 1;
			}
			while (f < b) {
				int mid = (f + b) / 2;
				if (nums[mid] == target) return mid;
				if (nums[mid] > target) b = mid;
				else f = mid + 1;
			}
			if (nums[f] == target) return f;
			return -1;

	}

	/*
	8ms �㲻�Ͽ죬ò������ʱ����4ms
	������������ô�ĺö�ΰ�������
	����ɶ��Ի���ô��
	*/
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		if(nums[nums.size()-1]>nums[0])
			return binarySearch(nums, 0, nums.size() - 1, target, false);
		return binarySearch(nums, 0, nums.size() - 1, target,true);
	}
	//��������������ʾʣ�µĲ�����ȫ������������ת��Ĳ��֣��������ת��Ĳ��֣���Ϊtrue
	int binarySearch(vector<int>& nums, int front, int back, int target,bool rotateExit) {
		if (front == back && nums[front] == target) return front;
		if (front == back) return -1;
		int mid = (front + back) / 2;
		if (nums[mid] == target) return mid;
		if (!rotateExit) {//������
			if(nums[mid]>target) return binarySearch(nums, front, mid, target, false);
			else return binarySearch(nums, mid+1, back, target, false);
		}
		else {//front��back���滹����ת������Ԫ��
			//mid����target
			if(target<nums[mid]&&nums[mid]<nums[back])
				return binarySearch(nums, mid+1, back, target, false);
			if (target<nums[mid]){
				int re = binarySearch(nums, front, mid, target, false);
				return re == -1 ? binarySearch(nums, mid+1, back, target, true) : re;
			}
			//midС��target
			if (target > nums[mid]&&nums[mid]>nums[back])
				return binarySearch(nums, mid + 1, back, target, true);
			if (target > nums[mid]) {
				int re = binarySearch(nums, front, mid, target, true);
				return re == -1 ? binarySearch(nums, mid + 1, back, target, false) : re;
			}
		}
	}
};

