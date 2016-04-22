//
//  main.cpp
//  Triangle
//
//  Created by apple on 16/1/23.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == triangle[i].size() - 1)
                triangle[i][j] += triangle[i - 1][j - 1];
            else {
                if (triangle[i - 1][j] < triangle[i - 1][j - 1])
                    triangle[i][j] += triangle[i - 1][j];
                else
                    triangle[i][j] += triangle[i - 1][j - 1];
            }
        }
    }
    int min = triangle[triangle.size() - 1][0];
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
        if (triangle[triangle.size() - 1][i] < min)
            min = triangle[triangle.size() - 1][i];
    }
    return min;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}
