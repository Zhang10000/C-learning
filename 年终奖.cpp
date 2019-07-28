#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getMost(vector<vector<int> > board) {
	for (int i = 1; i < board.size(); ++i) {
		board[0][i] += board[0][i - 1];
		board[i][0] += board[i - 1][0];
	}
	for(int i = 1; i < board.size(); ++i)
		for (int j = 1; j < board[0].size(); ++j)
			board[i][j] += max(board[i][j - 1], board[i - 1][j]);
	return board[board.size() - 1][board[0].size() - 1];
}
