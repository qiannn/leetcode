//
//  main.cpp
//  Surrounded Regions
//
//  Created by apple on 16/5/7.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector< vector<char> >& board) {
        if (board.empty())
            return;
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            //left col
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(i, 0, board);
            }
            //right col
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                dfs(i, n - 1, board);
            }
        }
        
        for (int i = 0; i < n; i++) {
            //top row
            if (board[0][i] == 'O') {
                board[0][i] = '#';
                dfs(0, i, board);
            }
            //bottom row
            if (board[m - 1][i] == 'O') {
                board[m - 1][i] = '#';
                dfs(m - 1, i, board);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
    
    void dfs(int x, int y, vector<vector<char>>& board) {
        
        if (x - 1 > -1 && board[x - 1][y] == 'O') {
            board[x - 1][y] = '#';
            dfs(x - 1, y, board);
        }
        
        if (x + 1 < board.size() && board[x + 1][y] == 'O') {
            board[x + 1][y] = '#';
            dfs(x + 1, y, board);
        }
        
        if (y - 1 > -1 && board[x][y - 1] == 'O') {
            board[x][y - 1] = '#';
            dfs(x, y - 1, board);
        }
        
        if (y + 1 < board[x].size() && board[x][y + 1] == 'O') {
            board[x][y + 1] = '#';
            dfs(x, y + 1, board);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<char> row1 = {'X','O','X','O'};
    vector<char> row2 = {'O','X','O','X'};
    vector<char> row3 = {'X','O','X','O'};
    vector<char> row4 = {'O','X','O','X'};
    vector<char> row5 = {'X','O','X','O'};
    vector<char> row6 = {'O','X','O','X'};
    
    vector< vector<char> > board;
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    
    Solution s;
    s.solve(board);
    
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
