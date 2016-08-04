#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool found = false;
	bool exist(vector< vector<char> >& board, string word) {
		vector< vector<bool> > mask(board.size(), vector<bool>(board[0].size(), true));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (DFS(mask, board, i, j, 0, word))
					return true;
			}
		}
		return false;
	}

	bool DFS(vector<vector<bool> >& mask, vector< vector<char> >& board, int x, int y, int index, string word) {
		if (word[index] == board[x][y]) {
			++index;
			if (index == word.length()){
				return true;
			}
		} else {
			return false;
		}

		
		mask[x][y] = false;

		if (x < board.size() - 1 && mask[x + 1][y] && board[x + 1][y] == word[index]) {
			if (DFS(mask, board, x + 1, y, index, word))
				return true;
		}
		if (x > 0 && mask[x - 1][y] && board[x - 1][y] == word[index]) {
			if (DFS(mask, board, x - 1, y, index, word))
				return true;
		}
		if (y < board[x].size() - 1 && mask[x][y + 1] && board[x][y + 1] == word[index]) {
			if (DFS(mask, board, x, y + 1, index, word))
				return true;
		}
		if (y > 0 && mask[x][y - 1] && board[x][y - 1] == word[index]) {
			if (DFS(mask, board, x, y - 1, index, word))
				return true;
		}
		mask[x][y] = true; 
		
		return false;	
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	/*
	vector< vector<char> > board = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	*/
	
	vector< vector<char> > board = {
		{'F','Y','C','E','N','R','D'},
		{'K','L','N','F','I','N','U'},
		{'A','A','A','R','A','H','R'},
		{'N','D','K','L','P','N','E'},
		{'A','L','A','N','S','A','P'},
		{'O','O','G','O','T','P','N'},
		{'H','P','O','L','A','N','O'}
	};
	
	string word = "poland";
	//string word = "ABCCED";
	//string word = "SEE";
	//string word = "ABCB";
	if (s.exist(board, word)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}