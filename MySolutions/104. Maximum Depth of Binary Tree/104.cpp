//============================================================================
// Name        : Leetcode.104. Maximum Depth of Binary Tree
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description :
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
    int maxDepth(TreeNode* root) {
    	if(root == nullptr)
    		return 0;
    	if(root->left == nullptr && root->right == nullptr)
    		return 1;
    	int leftDepth = root->left ? maxDepth(root->left) : INT_MIN;
    	int rightDepth = root->right ? maxDepth(root->right) : INT_MIN;

    	return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(3);
	struct TreeNode tn2(9);
	struct TreeNode tn3(20);
	struct TreeNode tn4(15);
	struct TreeNode tn5(7);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.left = &tn4;
	tn3.right = &tn5;

	Solution t;
	cout << t.maxDepth(&tn1) << endl;

	return 0;
}

