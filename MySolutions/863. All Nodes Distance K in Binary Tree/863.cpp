//============================================================================
// Name        : Leetcode.863. All Nodes Distance K in Binary Tree
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    	vector<pair<TreeNode*, int>> family;
    	family.push_back(pair<TreeNode*, int>(target, K));
    	while(family.back().first != root && family.back().second != 0) {
    		findParent(root, family);
    		//cout << " ---" << family.size() << endl;
    	}

    	//cout << " +++" << endl;
    	set<TreeNode*> hitSet;
    	vector<int> ans;
    	for(pair<TreeNode*, int> p : family) {
    		getDistanceK(p.first, p.second, hitSet, ans);
    	}

    	return ans;
    }
private:
    void findParent(TreeNode* node, vector<pair<TreeNode*, int>>& family) {
    	if(family.back().second == 0)
    		return;

    	TreeNode* target = family.back().first;

    	if(node->left) {
    		if(node->left == target) {
    			int K = family.back().second - 1;
    			family.push_back(pair<TreeNode*, int>(node, K));
    			return;
    		} else {
    			findParent(node->left, family);
    		}
    	}

    	if(node->right) {
    		if(node->right == target) {
    			int K = family.back().second - 1;
    			family.push_back(pair<TreeNode*, int>(node, K));
    			return;
    		} else {
    			findParent(node->right, family);
    		}
    	}
    }

    void getDistanceK(TreeNode* node, int K, set<TreeNode*>& hitSet, vector<int>& ans) {
    	if(node == nullptr)
    		return;

    	if(hitSet.count(node) == 0) {
			hitSet.insert(node);
			if(K == 0) {
				ans.push_back(node->val);
			} else {
				getDistanceK(node->left, K - 1, hitSet, ans);
				getDistanceK(node->right, K - 1, hitSet, ans);
			}
    	}
    	return;
    }
};

int main() {
	// Test Case
	int K = 2;
	struct TreeNode tn1(3);
	struct TreeNode tn2(5);
	struct TreeNode tn3(1);
	struct TreeNode tn4(6);
	struct TreeNode tn5(2);
	struct TreeNode tn6(0);
	struct TreeNode tn7(8);
	struct TreeNode tn8(7);
	struct TreeNode tn9(4);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.left = &tn4;
	tn2.right = &tn5;
	tn3.left = &tn6;
	tn3.right = &tn7;
	tn5.left = &tn8;
	tn5.right = &tn9;
	TreeNode* target = &tn2;

	/*
	int K = 3;
	struct TreeNode tn1(0);
	struct TreeNode tn2(2);
	struct TreeNode tn3(1);
	struct TreeNode tn4(3);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.left = &tn4;
	TreeNode* target = &tn4;
	*/

	Solution t;
	vector<int> ans = t.distanceK(&tn1, target, K);
	for(int i : ans)
		cout << i << " ";
	cout << endl;

	return 0;
}



