 /*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#pragma once
#include "LeetCode.h"
class MergeSortedArray
{
public:
	MergeSortedArray();
	~MergeSortedArray();
	//nums1�Ĵ�С�Ѿ���m+n��ֻ����������ò����Ĳ���Ĭ��Ϊ0����
	//Ϊ�˱���nums1��ֵ������Ҫ�Ӻ���ǰһ��һ���������
	//4ms����
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		auto rb1 = nums1.rbegin()+n, rb2 = nums2.rbegin(),rb1_new=nums1.rbegin();
		
		while (rb1_new != nums1.rend()) {
			if (rb1 == nums1.rend())
				*(rb1_new++) = *(rb2++);
			else if (rb2 == nums2.rend())
				*(rb1_new++) = *(rb1++);
			else
				*(rb1_new++) = *rb1 > *rb2 ? *(rb1++) : *(rb2++);
		}
	}
};

