//============================================================================
// Name        : Leetcode.671. Second Minimum Node In a Binary Tree
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
    	set<int> numSet;
    	travelTree(root, numSet);

    	if(numSet.size() < 2) {
    		return -1;
    	} else {
			set<int>::iterator smallest = numSet.begin();
			set<int>::iterator secondSmall = ++smallest;

			return *secondSmall;
    	}
    }
private:
    void travelTree(TreeNode* node, set<int>& numSet) {
    	if(node == nullptr)
    		return;

    	travelTree(node->left, numSet);
    	numSet.insert(node->val);
    	travelTree(node->right, numSet);
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(2);
	struct TreeNode tn2(2);
	struct TreeNode tn3(3);
	tn1.left = &tn2;
	tn1.right = &tn3;

	Solution t;
	cout << t.findSecondMinimumValue(&tn1) << endl;

	return 0;
}



