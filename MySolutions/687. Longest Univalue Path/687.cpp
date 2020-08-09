//============================================================================
// Name        : Leetcode.687. Longest Univalue Path
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
#include <unordered_set>
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
    int longestUnivaluePath(TreeNode* root) {
    	unordered_set<int> longests;
    	int longestPath = longestUnivaluePath(root, longests);
    	for(int i : longests) {
    		longestPath = max(longestPath, i);
    	}
    	return longestPath;
    }
private:
    int longestUnivaluePath(TreeNode* node, unordered_set<int>& longests) {
    	if(node == nullptr)
    		return 0;

    	int left = 0;
    	if(node->left) {
    		left = longestUnivaluePath(node->left, longests);
    		if(node->val != node->left->val) {
    			longests.insert(left);
    			left = 0;
    		} else {
    			++left;
    		}
    	}

    	int right = 0;
    	if(node->right) {
    		right = longestUnivaluePath(node->right, longests);
    		if(node->val != node->right->val) {
    			longests.insert(right);
    			right = 0;
    		} else {
    			++right;
    		}
    	}

    	if((node->left) && (node->right)) {
    		if(node->val == node->left->val && node->val == node->right->val)
    			longests.insert(left + right);
    	}

    	return max(left, right);
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(1);
	struct TreeNode tn2(4);
	struct TreeNode tn3(5);
	struct TreeNode tn4(4);
	struct TreeNode tn5(4);
	struct TreeNode tn6(5);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.left = &tn4;
	tn2.right = &tn5;
	tn3.right = &tn6;

//	struct TreeNode tn1(5);
//	struct TreeNode tn2(4);
//	struct TreeNode tn3(5);
//	struct TreeNode tn4(1);
//	struct TreeNode tn5(1);
//	struct TreeNode tn6(5);
//	tn1.left = &tn2;
//	tn1.right = &tn3;
//	tn2.left = &tn4;
//	tn2.right = &tn5;
//	tn3.right = &tn6;

	Solution t;
	cout << t.longestUnivaluePath(&tn1) << endl;


	return 0;
}



