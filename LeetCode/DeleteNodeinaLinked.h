/*
	Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

	Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

	ֱ�Ӹ���һ���ڵ㣬Ȼ��ɾ������ڵ�,��Щ��˵����ɵ�ƣ���������ʵ���⻹��
	����˼����ǿ϶���һ��ָ��ָ�����������ô���޸�ָ�룬ֱ�ӽ���������Ϊ��һ������
	�Ϳ�����ԭָ��ָ����һ������
*/
#pragma once
#include "LeetCode.h"
class DeleteNodeinaLinked
{
public:
	DeleteNodeinaLinked();
	~DeleteNodeinaLinked();

	void deleteNode(ListNode* node) {
		*node = *node->next;
	}
};

