//============================================================================
// Name        : Leetcode.938. Range Sum of BST
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
    int rangeSumBST(TreeNode* root, int L, int R) {
    	int node_val = (root->val >= L && root->val <= R) ? root->val : 0;

    	if(root == nullptr)
    		return 0;
    	if(root->left == nullptr && root->right == nullptr)
    		return node_val;
    	int left_sum = (root->left) ? rangeSumBST(root->left, L, R) : 0;
    	int right_sum = (root->right) ? rangeSumBST(root->right, L, R) : 0;

    	return left_sum + right_sum + node_val;
    }
};

int main() {
	// Test Case
	struct TreeNode ta1(10);
	struct TreeNode ta2(5);
	struct TreeNode ta3(15);
	struct TreeNode ta4(3);
	struct TreeNode ta5(7);
	struct TreeNode ta6(18);
	ta1.left = &ta2;
	ta1.right = &ta3;
	ta2.left = &ta4;
	ta2.right = &ta5;
	ta3.right = &ta6;
	int aL = 7, aR = 15;

	struct TreeNode tb1(10);
	struct TreeNode tb2(5);
	struct TreeNode tb3(15);
	struct TreeNode tb4(3);
	struct TreeNode tb5(7);
	struct TreeNode tb6(13);
	struct TreeNode tb7(18);
	struct TreeNode tb8(1);
	struct TreeNode tb9(6);
	tb1.left = &tb2;
	tb1.right = &tb3;
	tb2.left = &tb4;
	tb2.right = &tb5;
	tb3.right = &tb6;
	tb4.left = &tb8;
	tb5.left = &tb9;
	int bL = 6, bR = 10;

	Solution t;
	cout << t.rangeSumBST(&ta1, aL, aR) << endl;
	cout << t.rangeSumBST(&tb1, bL, bR) << endl;

	return 0;
}

