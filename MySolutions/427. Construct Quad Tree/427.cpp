//============================================================================
// Name        : Leetcode.427. Construct Quad Tree
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   : https://www.cnblogs.com/grandyang/p/9649348.html
//============================================================================
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
    	return construct(0, 0, grid.size(), grid);
    }
private:
    Node* construct(int x, int y, int len, vector<vector<int>>& grid) {
    	for(int i = x; i < x + len; i++) {
    		for(int j = y; j < y + len; j++) {
    			if(grid[i][j] != grid[x][y]) {
    				int newLen = len/2;
    				return new Node(true, false,
    						construct(x, y, newLen, grid),
							construct(x + newLen, y, newLen, grid),
							construct(x, y + newLen, newLen, grid),
							construct(x + newLen, y + newLen, newLen, grid)
					);
    			}
    		}
    	}
    	return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
    }
};

void showAns(Node* node) {
	if(node == nullptr)
		return;

	showAns(node->topLeft);
	showAns(node->topRight);
	cout << node->val << endl;
	showAns(node->bottomLeft);
	showAns(node->bottomRight);
}

int main() {
	// Test Case
	vector<vector<int>> grid{{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}};

	Solution t;
	Node* root = t.construct(grid);
	showAns(root);

	return 0;
}



