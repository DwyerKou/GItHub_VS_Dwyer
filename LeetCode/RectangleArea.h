/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.


*/
#pragma once
#include "LeetCode.h"
class RectangleArea
{
public:
	RectangleArea();
	~RectangleArea();
	/*
	�ȶԸ��Ե�x����������Ȼ��Ը��Ե�y����������Ȼ��С����ǰ��һ����������˳����˵Ļ�˵��x�����ص�
	ͬ���ж�y���ǲ������ص�
	û�ص�easyֱ�ӼӺ�
	���ص��Ļ�ȡ��������м�����x�м�����y�����ص���С�����ε������������������������
	������ô��
	�������һ���ߵ������ͬ������ֻ����������������0���ѣ�û��Ҫ��ǰд�������

	�ɹ�ͨ����56ms��˿�����찡������������������
	�󲿷���ͣ����32ms
	*/
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		vector<int> ax{ A,C },ay{ B,D },bx{ E, G },by{ F,H };
		sortVector(ax);
		sortVector(ay);
		sortVector(bx);
		sortVector(by);

		vector<int> x,y;
		if (ax[0] < bx[0])
			x = { ax[0],ax[1],bx[0],bx[1] };
		else
			x = { bx[0],bx[1] ,ax[0],ax[1] };

		if (ay[0] < by[0])
			y = { ay[0],ay[1],by[0],by[1] };
		else
			y = { by[0],by[1] ,ay[0],ay[1] };

		vector<int> x_backup(x), y_back(y);
		sortVector(x);
		sortVector(y);
		return computeArea(A, B, C, D) + computeArea(E, F, G, H) 
			- ((judgeVecotr(x, x_backup) || judgeVecotr(y, y_back)) ? 0 : computeArea(x[1], y[1], x[2], y[2]));
	}

	int computeArea(int A, int B, int C, int D) {
		return abs(A - C)*abs(B - D);
	}

	void sortVector(vector<int>& v) {
		sort(v.begin(), v.end());
	}

	bool judgeVecotr(vector<int>&x, vector<int>&y) {
		int n = x.size();
		for (size_t i = 0;i < n;++i)
			if (x[i] != y[i])
				return false;
		return true;
	}
};

