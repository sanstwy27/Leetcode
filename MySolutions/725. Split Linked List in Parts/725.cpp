//============================================================================
// Name        : Leetcode.725. Split Linked List in Parts
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   : 
// Description : 
// Reference   : https://zxi.mytechroad.com/blog/list/leetcode-725-split-linked-list-in-parts/
//============================================================================
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    	// Compute List Lenth
    	int list_len = 0;
    	for(ListNode* iter = root; iter; iter = iter->next) ++list_len;
    	int split_size      = list_len / k;
    	int split_frag_size = list_len % k;

    	// Split List
    	vector<ListNode*> ans(k, nullptr);
    	ListNode* prev = nullptr;
    	for(int i = 0; i < k; i++, split_frag_size--) {
    		ans[i] = root;
        	for(int j = 0; j < (split_size + (split_frag_size > 0)); j++) {
        		prev = root;
        		root = root->next;
        	}
        	if(prev) prev->next = nullptr;
    	}

    	return ans;
    }
};

int main() {
	// Test Case
	struct ListNode object1(1);
	struct ListNode object2(2);
	struct ListNode object3(3);
	struct ListNode object4(4);
	object1.next = &object2;
	object2.next = &object3;
	object3.next = &object4;

	Solution t;
	vector<ListNode*> v = t.splitListToParts(&object1, 3);
	cout << "[";
    for(vector<ListNode*>::iterator iter = v.begin(); iter != v.end(); iter++) {
		if(iter != v.begin()) cout << ", ";
		cout << "[";
        for(ListNode* tmp = *iter; tmp; tmp = tmp->next) {
        	cout << tmp->val;
            if(tmp->next != nullptr) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;

	return 0;
}
