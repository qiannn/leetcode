//
//  main.cpp
//  Set Matrix Zeroes
//
//  Created by apple on 15/12/2.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class point {
public:
    int row;
    int col;
    point(int x, int y):row(x), col(y){};
};

void setRowAndColto0(vector<vector<int>>& matrix, int row, int col) {
    for (int i = 0; i < matrix[row].size(); ++i) {
        matrix[row][i] = 0;
    }
    
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][col] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<point> zeroset;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                zeroset.push_back(point(i, j));
            }
        }
    }
    
    for (int i = 0; i < zeroset.size(); ++i) {
        setRowAndColto0(matrix, zeroset[i].row, zeroset[i].col);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<vector<int>> matrix = {{1,2,3,4},{2,3,0,1},{0,1,3,9}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
