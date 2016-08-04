//
//  main.cpp
//  Pascal's Triangle II
//
//  Created by apple on 15/11/17.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRows(int rowIndex) {
    vector<int> row = {1};
    
    while (rowIndex --) {
        for (int i = row.size() - 1; i > 0; i--) {
            row[i] += row[i-1];
        }
        row.push_back(1);
    }
    
    return row;
}

int main(int argc, const char * argv[]) {
    vector<int> ans = getRows(1);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
