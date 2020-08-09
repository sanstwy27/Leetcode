//============================================================================
// Name        : Leetcode.558. Quad Tree Intersection
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
    	if(quadTree1 == nullptr && quadTree2 == nullptr) return nullptr;
    	if(quadTree1 == nullptr) return quadTree2;
    	if(quadTree2 == nullptr) return quadTree1;

    	if(quadTree1->isLeaf && quadTree2->isLeaf) {
    		return new Node((quadTree1->val || quadTree2->val), true, nullptr, nullptr, nullptr, nullptr);
    	} else {
    		if(quadTree1->isLeaf && quadTree1->val)
    			return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
    		if(quadTree2->isLeaf && quadTree2->val)
    			return new Node(true, true, nullptr, nullptr, nullptr, nullptr);

    		Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
    		Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
			Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
			Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
			if(tl && tr && bl && br) {
				if(tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
					return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
				}
			}
			return new Node(quadTree1->val || quadTree2->val, false, tl, tr, bl, br);
    	}
    }
};

void showAns(Node* node, int indent) {
	if(node == nullptr)
		return;


	for(int i = 0; i < indent; i++) cout << " ";
	cout << "{" << endl;

	showAns(node->topLeft, indent + 2);
	showAns(node->topRight, indent + 2);
	for(int i = 0; i < indent * 2; i++) cout << " ";
	cout << "val:" << node->val << ", isLeaf:" << node->isLeaf << " ";
	cout << "topLeft:" << (node->topLeft == nullptr) << ", topRight:" << (node->topRight == nullptr) << " ";
	cout << "bottomLeft:" << (node->bottomLeft == nullptr) << ", bottomRight:" << (node->bottomRight == nullptr) << endl;
	showAns(node->bottomLeft, indent + 2);
	showAns(node->bottomRight, indent + 2);

	for(int i = 0; i < indent; i++) cout << " ";
	cout << "}" << endl;
}

int main() {
	// Test Case
	Node* n1 = new Node(true, false,
			new Node(true, true, nullptr, nullptr, nullptr, nullptr),
			new Node(true, true, nullptr, nullptr, nullptr, nullptr),
			new Node(false, true, nullptr, nullptr, nullptr, nullptr),
			new Node(false, true, nullptr, nullptr, nullptr, nullptr));
	Node* n2 = new Node(true, false,
			new Node(true, true, nullptr, nullptr, nullptr, nullptr),
			new Node(true, false,
					new Node(false, true, nullptr, nullptr, nullptr, nullptr),
					new Node(false, true, nullptr, nullptr, nullptr, nullptr),
					new Node(true, true, nullptr, nullptr, nullptr, nullptr),
					new Node(true, true, nullptr, nullptr, nullptr, nullptr)),
			new Node(true, true, nullptr, nullptr, nullptr, nullptr),
			new Node(false, true, nullptr, nullptr, nullptr, nullptr));


	Solution t;
	showAns(t.intersect(n1, n2), 2);

	return 0;
}



