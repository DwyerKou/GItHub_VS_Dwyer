/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#pragma once
#include "LeetCode.h"
class MergeIntervals
{
public:
	MergeIntervals();
	~MergeIntervals();
	/*
	˼·��
		�Ȱ���start����Ȼ���������back�ĵ�һ����ǰ��end���Ļ���ʱ������
	�������Ǽ���start��Ҫ<=end ��Ȼû˵���������������䰡����
	֮ǰ��һ������ʱ��û�п��ǵ����ܴ������串�ǵ���û��AC
	�����˿������������
	580ms
	*/
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() < 2) return intervals;
		vector<Interval> re;
		sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {return a.start < b.start;});
		auto front = intervals.begin(), back = intervals.begin()+1;
		int max = (*front).end;
		while (back!= intervals.end()) {
			if (max < (*back).start) {
				re.push_back(Interval((*front).start, max));
				front=back;
				max = (*front).end;
				back++;
			}else{
				if (max < (*back).end)
					max = (*back).end;
				back++;
			}
		}
		re.push_back(Interval((*front).start, max));
		return re;
	}
};

