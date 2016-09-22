#ifndef __LEETCODE_19
#define __LEETCODE_19
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* p1, *p2;
		p1 = head;
		p2 = head;
		for (size_t i = 0; i < n-1; i++)
			p2 = p2->next;

		ListNode* pre = NULL;
		while (p2->next)
		{
			
			p2 = p2->next;
			pre = p1;
			p1 = p1->next;
		}
		if (pre!=NULL){
			pre->next = p1->next;
			delete(p1);
		}
		else{
			head = head->next;
		}
		return head;
	}
};

#endif