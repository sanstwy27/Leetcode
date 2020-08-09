//============================================================================
// Name        : Leetcode.21. Merge Two Sorted Lists
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l2 == nullptr)
    		return l1;
    	if(l1 == nullptr)
    		return l2;

    	ListNode* ans;
    	if(l1->val == l2->val) {
    		ans = l1;
    		ListNode* tmp = mergeTwoLists(l1->next, l2->next);
    		l1->next = l2;
    		l2->next = tmp;
    	} else if(l1->val < l2->val) {
    		ans = l1;
   			for( ;l1->next != nullptr; l1 = l1->next) {
   				if(l1->next->val >= l2->val) {
   					break;
   				}
    		}
    		ListNode* tmp = mergeTwoLists(l1->next, l2->next);
    		l1->next = l2;
    		l2->next = tmp;
    	} else {
    		ans = l2;
   			for( ;l2->next != nullptr; l2 = l2->next) {
   				if(l2->next->val >= l1->val) {
   					break;
   				}
    		}
    		ListNode* tmp = mergeTwoLists(l1->next, l2->next);
    		l2->next = l1;
    		l1->next = tmp;
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	//struct ListNode l1_1(1);
	//struct ListNode l1_2(2);
	//struct ListNode l1_3(4);
	//struct ListNode l2_1(1);
	//struct ListNode l2_2(3);
	//struct ListNode l2_3(4);
	//l1_1.next = &l1_2;
	//l1_2.next = &l1_3;
	//l2_1.next = &l2_2;
	//l2_2.next = &l2_3;

	struct ListNode l1_1(5);
	struct ListNode l2_1(1);
	struct ListNode l2_2(2);
	struct ListNode l2_3(4);
	l2_1.next = &l2_2;
	l2_2.next = &l2_3;

	Solution t;
	ListNode* ans = t.mergeTwoLists(&l1_1, &l2_1);
	for(; ans != nullptr; ans = ans->next) cout << " " << ans->val;
	cout << endl;

	return 0;
}



