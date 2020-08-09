//============================================================================
// Name        : Leetcode.501. Find Mode in Binary Search Tree
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
#include <map>
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
    vector<int> findMode(TreeNode* root) {
    	map<int, int> map;
    	findMode(root, map);

    	vector<int> ans;
    	int curMax = 0;
    	for(std::map<int, int>::iterator iter = map.begin(); iter != map.end(); iter++) {
    		if(curMax < iter->second) {
    			ans.clear();
    			ans.push_back(iter->first);
    			curMax = iter->second;
    		} else if(curMax == iter->second){
    			ans.push_back(iter->first);
    		}
    	}

    	return ans;
    }
private:
    void findMode(TreeNode* node, map<int, int>& map) {
    	if(node == nullptr)
    		return;

    	findMode(node->left, map);
    	++map[node->val];
    	findMode(node->right, map);
    }
};

int main() {
	// Test Case
	struct TreeNode tn1(1);
	struct TreeNode tn2(2);
	tn1.right = &tn2;

	Solution t;
	vector<int> ans = t.findMode(&tn1);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}



