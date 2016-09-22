#ifndef __LEETCODE_2
#define __LEETCODE_2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		ListNode* head = new ListNode(0);
		ListNode* index =head;
		int carry = 0;
		while (l1 && l2)
		{
			ListNode* temp = new ListNode((l1->val + l2->val + carry) % 10);
			index->next = temp;
			index = index->next;
			carry = (l1->val + l2->val + carry) / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1){ 
			
				ListNode* temp = new ListNode((l1->val + carry) % 10);
				index->next = temp;
				index = index->next;
				carry = (l1->val + carry) / 10;
				l1 = l1->next;
		
		}
		while (l2){ 
			ListNode* temp = new ListNode((l2->val + carry) % 10);
			index->next = temp;
			index = index->next;
			carry = (l2->val + carry) / 10;
			l2 = l2->next;

		}
		if (carry != 0)
		{
			ListNode* temp = new ListNode(carry);
			index->next = temp;

		}
		return head-> next;
	}
};

#endif