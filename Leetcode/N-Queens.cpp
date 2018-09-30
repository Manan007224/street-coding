//solving the N-Queens Problem using backtracking.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool valid_pos(vector<vector <int> > &board, int r, int c) {
	for(int i=0;i<c;i++) {
		if(board[r][i] == 1) return false;
	}
	for (int i=r, j=c; i>=0 && j>=0; i--, j--) {
		 if(board[i][j] == 1) return false;
	}   
    for (int i=r, j=c; j>=0 && i<board[0].size(); i++, j--) {
        if(board[i][j] == 1) return false;
    }
    return true;
}

bool solve(vector< vector<int> > &board, int c) {
	if(c >= board[0].size()) return true;
	for(int i=0;i<board[0].size();i++) {
		if(valid_pos(board,i,c)) {
			board[i][c] = 1;
			if(solve(board,c+1)) 
				return true;
			board[i][c] = 0;
		}
	}
	return false;
}

int main() {
	int N; 
	cout << "Enter the number of queens in the ChessBoard" << endl;
	cin >> N;
	vector< vector<int> > board(N, vector<int>(N));
	cout << "Size of the Board is" << board[0].size() << endl;
	if(solve(board,0) == true) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}
	else cout << "Sorry not posible" << endl;
	return 0;
}

