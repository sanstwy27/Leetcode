//============================================================================
// Name        : Leetcode.876. Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
    	if(head == nullptr)
    		return head;

    	int len = 1;
    	ListNode* ans;
    	for(ans = head; ans->next != nullptr; ans = ans->next) ++len;

    	ans = head;
    	int move = (len % 2 == 1) ? (len + 1) / 2 : (len / 2) + 1;
    	for(int i = 1; i < move; i++)
    		ans = ans->next;

    	return ans;
    }
};

int main() {
	// Test Case
	struct ListNode ln1(1);
	struct ListNode ln2(2);
	//struct ListNode ln3(3);
	//struct ListNode ln4(4);
	//struct ListNode ln5(5);
	ln1.next = &ln2;
	//ln2.next = &ln3;
	//ln3.next = &ln4;
	//ln4.next = &ln5;
	Solution t;
	ListNode * ans = t.middleNode(&ln1);
	if(ans)
		cout << ans->val << endl;

	return 0;
}



