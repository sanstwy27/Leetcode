//============================================================================
// Name        : Leetcode.61. Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == nullptr || k == 0) return head;

    	// Get List Length
    	int listLen = 0;
    	ListNode* fast = head;
    	for(; fast != nullptr; fast = fast->next) listLen++;

    	// *Fast* Start First
    	fast = head;
    	for(int move = 0; move < (k % listLen); move++) {
    		fast = fast->next;
    	}

    	// And *Slow* Start
    	ListNode* slow = head;
    	for(; fast->next != nullptr; fast = fast->next, slow = slow->next);

    	// Update List
    	fast->next = head;
    	head = slow->next;
    	slow->next = nullptr;

    	return head;
    }
};

int main() {
	// Test Case
	struct ListNode ln1(1);
	struct ListNode ln2(2);
	struct ListNode ln3(3);
	struct ListNode ln4(4);
	struct ListNode ln5(5);
	ln1.next = &ln2;
	ln2.next = &ln3;
	ln3.next = &ln4;
	ln4.next = &ln5;

	Solution t;
	ListNode* cur = t.rotateRight(&ln1, 2);
	for(; cur; cur = cur->next) {
		cout << cur->val << endl;
	}

	return 0;
}



