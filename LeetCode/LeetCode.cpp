// LeetCode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BSTIterator.h"
int _tmain(int argc, _TCHAR* argv[])
{
	
	TreeNode *root = new TreeNode(1);
	BSTIterator i = BSTIterator(root);
	while (i.hasNext())
		cout << i.next() << endl;
	return 0;
}
