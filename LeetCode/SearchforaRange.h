/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#pragma once
#include "LeetCode.h"
class SearchforaRange
{
public:
	SearchforaRange();
	~SearchforaRange();
	/*
		ԭ���������򣬿��Զ���
		9.5����д
		Ҫ����O(lgn)��ʱ�䣬���Բ��������ҵ�targetȻ��������Ѱ�ҵķ���
		�����ң���һ���ҵ��±߽磬�ڶ����ҵ��ϱ߽�
		һ���
		12ms ���
	*/
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> re{-1,-1};
		int left = 0,right = nums.size() - 1;
		//�����Ҫ�ҵ���߽� ��leftָ����߽�
		while (left < right) {
			if (nums[left] == target) break;
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			if (nums[mid] > target) right = mid - 1;
			if (nums[mid] == target) {
				if(nums[mid-1]<nums[mid]){
					left = mid;
					break;
				}
				else
					right = mid;
			}
		}
		if (nums[left] != target) //˵������������
			return re;
		re[0] = left;
		//�����Ҫ�ҵ��ұ߽�
		right = nums.size() - 1;
		while (left < right) {
			if (nums[right] == target) break;
			int mid = (left + right) / 2;
			if(nums[mid] < target) left = mid + 1;
			if (nums[mid] > target) right = mid - 1;
			if (nums[mid] == target) {
				if (nums[mid] < nums[mid + 1]) {
					right = mid;
					break;
				}
				else
					left = mid;
			}
		}
		re[1] = right;
		return re;
	}
};

