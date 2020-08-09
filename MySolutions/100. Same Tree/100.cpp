//============================================================================
// Name        : Leetcode.100. Same Tree
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(p == nullptr && q == nullptr)
    		return true;
    	if(p != nullptr && q == nullptr)
    		return false;
    	if(p == nullptr && q != nullptr)
    		return false;

    	bool left = isSameTree(p->left, q->left);
    	bool node = (p->val == q->val);
    	bool right = isSameTree(p->right, q->right);

    	return left && node && right;
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(1);
	struct TreeNode tn2(2);
	struct TreeNode tn3(1);
	struct TreeNode tn4(1);
	struct TreeNode tn5(2);
	struct TreeNode tn6(1);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn4.left = &tn5;
	tn4.right = &tn6;

	Solution t;
	cout << t.isSameTree(&tn1, &tn4) << endl;



	return 0;
}



