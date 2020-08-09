//============================================================================
// Name        : Leetcode.114. Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
    	root = rotate(root);
    }
private:
    TreeNode* rotate(TreeNode* node) {
    	if(node == nullptr) {
    		return node;
    	} else if(node->left == nullptr) {
    		rotate(node->right);
    	} else if(node->right == nullptr) {
    		node->right = node->left;
    		node->left = nullptr;
    		rotate(node->right);
    	} else {
			TreeNode* left = node->left;
			TreeNode* right = node->right;

			left = rotate(left);
			TreeNode* tmp = node;
			for(tmp = left; tmp->right != nullptr; tmp = tmp->right);
			right = rotate(right);
			tmp->right = right;

			node->right = left;
			node->left = nullptr;
    	}

    	return node;
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(1);
	struct TreeNode tn2(2);
	struct TreeNode tn3(3);
	struct TreeNode tn4(4);
	struct TreeNode tn5(5);
	struct TreeNode tn6(6);
	tn1.left = &tn2;
	tn1.right = &tn5;
	tn2.left = &tn3;
	tn2.right = &tn4;
	tn5.right = &tn6;

	Solution t;
	t.flatten(&tn1);
	TreeNode* ptr = &tn1;
	for(; ptr != nullptr; ptr = ptr->right) cout << ptr->val << endl;

	return 0;
}



