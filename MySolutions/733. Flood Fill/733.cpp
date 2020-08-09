//============================================================================
// Name        : Leetcode.733. Flood Fill
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    	flooding(image, sr, sc, newColor);
    	return image;
    }
private:
    void flooding(vector<vector<int>>& image, int sr, int sc, int newColor) {
    	int ori = image[sr][sc];
    	if(newColor == ori) return;

    	image[sr][sc] = newColor;
    	if(sr - 1 >= 0)
    		if((image[sr - 1][sc] == ori))
    			flooding(image, sr - 1, sc, newColor);
    	if(sr + 1 < image.size())
    		if((image[sr + 1][sc] == ori))
    			flooding(image, sr + 1, sc, newColor);
    	if(sc - 1 >= 0)
    		if((image[sr][sc - 1] == ori))
    			flooding(image, sr, sc - 1, newColor);
    	if(sc + 1 < image[0].size())
    		if((image[sr][sc + 1] == ori))
    			flooding(image, sr, sc + 1, newColor);
    }
};

int main() {
	// Test Case
	//vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};
	//int sr = 1, sc = 1, newColor = 2;
	vector<vector<int>> image{{0,0,0},{0,1,1}};
	int sr = 1, sc = 1, newColor = 1;

	//cout << image[1][2] << endl;

	Solution t;
	t.floodFill(image, sr, sc, newColor);
	for(vector<int> r : image) {
		for(int c : r) {
			cout << c << " ";
		}
		cout << endl;
	}

	return 0;
}



