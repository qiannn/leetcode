//
//  main.cpp
//  Pascal's Triangle
//
//  Created by apple on 15/11/11.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> pascal;
    vector<int> row = {1};
    
    while (numRows--) {
        pascal.push_back(row);
        vector<int> tempRows;
        vector<int>::iterator iter;
        for (iter = row.begin(); iter != row.end(); iter++) {
            int p = 0;
            if (iter != row.begin()) {
                p = *(iter - 1);
            }
            tempRows.push_back(*iter + p);
        }
        tempRows.push_back(1);
        row = tempRows;
    }
    
    return pascal;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> pascal = generatePascal(5);
    vector<int>::iterator iter1;
    vector<vector<int>>::iterator iter2;
    
    for (iter2 = pascal.begin(); iter2 != pascal.end(); iter2++) {
        for (iter1 = (*iter2).begin(); iter1 != (*iter2).end(); iter1 ++) {
            cout<<*iter1<<" ";
        }
        cout<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
