//============================================================================
// Name        : Leetcode.894. All Possible Full Binary Trees
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
#include <unordered_map>
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
    vector<TreeNode*> allPossibleFBT(int N) {
    	if((N % 2) == 0) return {};
    	if(N == 1) return {new TreeNode(0)};

    	vector<TreeNode*> ans;
    	for(int i = 1; i < N; i += 2) {
    		vector<TreeNode*> left = allPossibleFBT(i);
    		vector<TreeNode*> right = allPossibleFBT(N - i - 1);

    		for(auto leftT : left)
    			for(auto rightT : right) {
    	    		TreeNode *cur = new TreeNode(0);
    	    		cur->left = leftT;
    	    		cur->right = rightT;
    	    		ans.push_back(cur);
    			}
    	}

    	return ans;
    }
};

void showAns(TreeNode* cur) {
	cout << "[" << cur->val << "]";

	if(cur->left == nullptr && cur->right == nullptr)
		cout << "[null][null]";

	if(cur->left) showAns(cur->left);
	//else cout << "[null]";

	if(cur->right) showAns(cur->right);
	//else cout << "[null]";
}

int main() {
	// Test Case

	Solution t;
	vector<TreeNode*> ans = t.allPossibleFBT(7);
	cout << "count:" << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << "[";
		showAns(ans[i]);
		cout << "]" << endl;
	}

	return 0;
}



