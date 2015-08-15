/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also
have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists
and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/
#pragma once
#include "LeetCode.h"
class CourseSchedule
{
public:
	CourseSchedule();
	~CourseSchedule();
	/*
	�������һ��������������
	������������ȣ�������ڻ��Ļ���ͬһ�ſλ��ٴγ���
	������ȿ����ö�ջʵ��
	�Ƚ��鷳����ͼ�ṹ�Ĵ洢���Ҽƻ��ſ��ٺܶ�set�洢ͼ�ṹ
	Ȼ��Ҫ�ҵ��������Ϊ0�Ľڵ�

	ͨ���� ��������������������ʱ����252ms��ͦ���
	*/
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<set<int>> v(numCourses);
		vector<int> searched(numCourses, 0);//���һ�����Ѿ�����һ��ջ�����Ժ���Ҳ����Ҫ������㵱��forѭ���ĵ�һ����
		for (auto p : prerequisites)
			v[p.second].insert(p.first);
		stack<int> s;
		for (int i = 0;i < numCourses&&searched[i] == 0;++i) {
			s.push(i);
			searched[i] = 1;
			vector<int> allready(numCourses, 0);//�����ݹ����ж��ǲ����Ѿ����ֹ��ˣ�ÿ�ν�ջ��Ϊ1����ջ��Ϊ0�������ջ���Ѿ���1�ˣ�˵���л�������false
			allready[i] = 1;
			while (!s.empty()) {
				int top = s.top();
				if (!v[s.top()].empty()) {
					auto it = v[top].begin();
					if (allready[*it] == 1)
						return false;
					else {
						allready[*it] = 1;
						searched[*it] = 1;
						s.push(*it);
						v[top].erase(it);
					}
				}
				else {
					allready[top] = 0;
					s.pop();
				}
			}
		}
		return true;
	}
};

