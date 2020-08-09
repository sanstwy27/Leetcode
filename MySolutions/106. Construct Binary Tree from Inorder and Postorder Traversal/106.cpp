//============================================================================
// Name        : Leetcode.106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if((inorder.empty() || postorder.empty()) || (inorder.size() != postorder.size()))
    		return nullptr;

    	TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    	return root;
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int leftI, int rightI, vector<int>& postorder, int leftP, int rightP) {
    	if((rightI - leftI + 1) == 0 || (rightP - leftP + 1) == 0)
    		return nullptr;

    	TreeNode* root = new TreeNode(postorder[rightP]);

    	// Get Left and Right Inorder Vectors
    	bool leftTurn = true;
    	int leftCount = 0, rightCount = 0;
    	for(int i = leftI; i < rightI + 1; i++) {
    		if(inorder[i] == root->val) {
    			leftTurn = false;
    			continue;
    		}

    		if(leftTurn) {
    			++leftCount;
    		} else{
    			++rightCount;
    		}
    	}

    	root->left = buildTree(inorder, leftI, leftI + leftCount - 1, postorder, leftP, leftP + leftCount - 1);
    	root->right = buildTree(inorder, leftI + leftCount + 1, leftI + leftCount + rightCount, postorder, leftP + leftCount, leftP + leftCount + rightCount - 1);

    	return root;
    }
};

void showAns(TreeNode* root) {
	if(root == nullptr)
		return;

	showAns(root->left);
	cout << " " << root->val;
	showAns(root->right);
}

int main() {
	// Test Case
	vector<int> inorder{9,3,15,20,7};
	vector<int> postorder{9,15,7,20,3};

	Solution t;
	showAns(t.buildTree(inorder, postorder));
	cout << endl;

	return 0;
}



