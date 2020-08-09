//============================================================================
// Name        : Leetcode.113. Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> ans;
    	vector<int> curAns;
    	pathSum(root, sum, 0, curAns, ans);
    	return ans;
    }
private:
    void pathSum(TreeNode* node, int targetSum, int curSum, vector<int>& curAns, vector<vector<int>>& ans) {
    	if(node == nullptr)
    		return;

    	if(node->left == nullptr && node->right == nullptr) {
    		if((curSum + node->val) == targetSum) {
    			curAns.push_back(node->val);
    			ans.push_back(curAns);
    			curAns.pop_back();
    		}
    	}

    	curAns.push_back(node->val);
    	pathSum(node->left, targetSum, curSum + node->val, curAns, ans);
    	pathSum(node->right, targetSum, curSum + node->val, curAns, ans);
    	curAns.pop_back();
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(5);
	struct TreeNode tn2(4);
	struct TreeNode tn3(8);
	struct TreeNode tn4(11);
	struct TreeNode tn5(13);
	struct TreeNode tn6(4);
	struct TreeNode tn7(7);
	struct TreeNode tn8(2);
	struct TreeNode tn9(5);
	struct TreeNode tn10(1);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.left = &tn4;
	tn4.left = &tn7;
	tn4.right = &tn8;
	tn3.left = &tn5;
	tn3.right = &tn6;
	tn6.left = &tn9;
	tn6.right = &tn10;

	Solution t;
	vector<vector<int>> ans = t.pathSum(&tn1, 22);
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << " " << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}



