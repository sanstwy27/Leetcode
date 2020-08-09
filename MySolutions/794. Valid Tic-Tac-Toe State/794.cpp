//============================================================================
// Name        : Leetcode.794. Valid Tic-Tac-Toe State
// Author      : sanstwy27
// Version     : Version 1.0.0
// Copyright   :
// Description : Any %
// Reference   :
//============================================================================
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	const char xc = 'X', oc = 'O', sc = ' ';
	const string xs = "XXX", os = "OOO";
public:
    bool validTicTacToe(vector<string>& board) {
    	if(board.size() != 3
    			|| board[0].length() != 3
				|| board[1].length() != 3
				|| board[2].length() != 3)
    		return false;


    	int xCount = 0, oCount = 0, sCount = 0;
    	for(int i = 0; i < board.size(); i++) {
    		xCount += std::count(board[i].begin(), board[i].end(), xc);
    		oCount += std::count(board[i].begin(), board[i].end(), oc);
    		sCount += std::count(board[i].begin(), board[i].end(), sc);
    	}
    	if(oCount > xCount || (xCount - oCount) > 1) return false;


    	int xOverCount = getOverCount(board, xs);
    	int oOverCount = getOverCount(board, os);
    	if(sCount > 0) {
			if(xOverCount > 1 || oOverCount > 1) return false;
			// "XXX","XOO","OO " => false
			if(xOverCount == 1 && (xCount == oCount)) return false;
    	} else {
    		if(oOverCount > 0) return false;
    	}


    	return true;
    }
private:
    int getOverCount(vector<string>& board, const string& key) {
    	int count = 0;

    	std::string dia1{board[0][0], board[1][1], board[2][2]};
    	std::string dia2{board[2][0], board[1][1], board[0][2]};
    	if(key == dia1) ++count;
    	if(key == dia2) ++count;

    	std::string col1{board[0][0], board[1][0], board[2][0]};
    	std::string col2{board[0][1], board[1][1], board[2][1]};
    	std::string col3{board[0][2], board[1][2], board[2][2]};
    	if(key == col1) ++count;
    	if(key == col2) ++count;
    	if(key == col3) ++count;

    	for(int i = 0; i < board.size(); i++) {
    		if(board[i] == key) ++count;
    	}

    	return count;
    }
};

int main() {
	// Test Case
	vector<string> board{"OXX","XOX","OXO"};

	Solution t;
	cout << t.validTicTacToe(board) << endl;

	return 0;
}



