#ifndef __LEETCODE_61
#define __LEETCODE_61
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
	static ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return  NULL;
		if (k == 0)
			return head;
		ListNode* ptr1 = head;
		ListNode* ptr2 = ptr1;
		int len = 0;
		for (ListNode *node = head; node != NULL; node = node->next) {
			len++;
		}
		k = k % len;
		if (k == 0)
			return head;
		for (int i = 0; i < k&& ptr2->next!=NULL; i++)
			ptr2 = ptr2->next;
		
		while (ptr2->next){ ptr1 = ptr1->next; ptr2 = ptr2->next; }
		ListNode* newhead = ptr1->next;
		ptr1->next = NULL;
		ptr2->next = head;
		return newhead;
	}
};


#endif