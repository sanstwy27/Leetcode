//============================================================================
// Name        : Leetcode.111. Minimum Depth of Binary Tree
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
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == nullptr)
        	return 0;
        if(root->left == nullptr && root->right == nullptr)
        	return 1;
        int left_min = (root->left) ? minDepth(root->left) : INT_MAX;
        int right_min = (root->right) ? minDepth(root->right) : INT_MAX;

        return min(left_min, right_min) + 1;
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(3);
	struct TreeNode tn2(9);
	struct TreeNode tn3(20);
	struct TreeNode tn4(15);
	struct TreeNode tn5(7);
	struct TreeNode tn6(11);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.left = &tn4;
	tn3.right = &tn5;
	tn5.left = &tn6;

	Solution t;
	cout << t.minDepth(&tn1) << endl;
	cout << t.minDepth(NULL) << endl;
	cout << t.minDepth(&tn4) << endl;
	cout << t.minDepth(&tn5) << endl;

	return 0;
}
