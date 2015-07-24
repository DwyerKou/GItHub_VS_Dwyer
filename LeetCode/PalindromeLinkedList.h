/***********************
*Date:2015.7.16
*Problems:Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*����	�ҵķ���O(n)���ǿռ�������O(1)
		�кܶ��˰�����ת��һ�£������⿪���˿ռ�
		����˵�ռ�������O��n����Ϊ��
			(1) a program using O(1) space is computationally equivalent to a finite automata, or a regular expression checker; 
			(2) the pumping lemma states that the set of palindrome strings does not form a regular set.
***********************/
#pragma once
#include <vector>
using namespace std;
class PalindromeLinkedList
{
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
		
	};

	PalindromeLinkedList();
	~PalindromeLinkedList();
	bool isPalindrome(ListNode* head) {
		vector<int> v;
		while (head != NULL){
			v.push_back(head->val);
			head = head->next;
		}
		if (v.size() < 2) return true;
		auto front= v.begin();
		auto back = --v.end();
		while (front < back){
			if (*front != *back)
				return false;
			++front;
			--back;
		}
		return true;
	}
};

