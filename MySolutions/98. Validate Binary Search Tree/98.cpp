//============================================================================
// Name        : Leetcode.98. Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
    	if(root == nullptr)
    		return true;

    	return isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValidBST(TreeNode* node, long lower, long upper) {
    	if(node == nullptr)
    		return true;

    	if(node->val <= lower || node->val >= upper)
    		return false;

    	return isValidBST(node->left, lower, node->val) && isValidBST(node->right, node->val, upper);
    }
};

int main() {
	// Test Case
	/*
	struct TreeNode tn1(5);
	struct TreeNode tn2(1);
	struct TreeNode tn3(7);
	struct TreeNode tn4(6);
	struct TreeNode tn5(8);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.left = &tn4;
	tn3.right = &tn5;
	*/

	struct TreeNode tn1(2147483647);
	struct TreeNode tn2(-2147483647);
	tn1.left = &tn2;

	//struct TreeNode tn1(2147483647);

	/*
	struct TreeNode tn1(10);
	struct TreeNode tn2(5);
	struct TreeNode tn3(15);
	struct TreeNode tn4(-2147483648);
	struct TreeNode tn5(20);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.left = &tn4;
	tn3.right = &tn5;
	*/


	Solution t;
	cout << t.isValidBST(&tn1) << endl;


	return 0;
}



