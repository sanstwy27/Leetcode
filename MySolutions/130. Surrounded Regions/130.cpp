//============================================================================
// Name        : Leetcode.130. Surrounded Regions
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	if(board.size() < 1) return;

    	set<pair<int,int>> circles;
    	for(int x = 0; x < board.size(); x++) {
    		for(int y = 0; y < board[x].size(); y++) {
    			if(x == 0 || x == board.size() - 1 || y == 0 || y == board[x].size() - 1)
    				dfs(x, y, circles, board);
    		}
    	}

    	for(int i = 0; i < board.size(); i++) {
    		for(int j = 0; j < board[i].size(); j++) {
    			if(board[i][j] == 'O') {
    				if(circles.count({i, j}) == 0) {
    					board[i][j] = 'X';
    				}
    			}
    		}
    	}
    }
private:
    void dfs(int x, int y, set<pair<int,int>>& circles, vector<vector<char>>& board) {
    	if(board[x][y] == 'O') {
			if(circles.count({x, y}) == 0) {
				circles.insert({x,y});

				if((x + 1) < board.size()) {
					if(board[x + 1][y] == 'O')
						dfs(x + 1, y, circles, board);
				}

				if((x - 1) >= 0) {
					if(board[x - 1][y] == 'O')
						dfs(x - 1, y, circles, board);
				}

				if((y + 1) < board[0].size()) {
					if(board[x][y + 1] == 'O')
						dfs(x, y + 1, circles, board);
				}

				if((y - 1) >= 0) {
					if(board[x][y - 1] == 'O')
						dfs(x, y - 1, circles, board);
				}
			}
    	}
    }
};

void showAns(vector<vector<char>>& board) {
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	// Test Case
	//vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	//vector<vector<char>> board{{'O','O'},{'O','O'}};
	//vector<vector<char>> board{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
	vector<vector<char>> board{{'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'}};

	Solution t;
	t.solve(board);
	showAns(board);

	return 0;
}



