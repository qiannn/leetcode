//
//  main.cpp
//  Unique Paths
//
//  Created by apple on 15/12/21.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

int uniquePaths(int m, int n) {
    int dp[100][100];
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                dp[0][j] = 1;
            }
            else if (j == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << uniquePaths(2, 3) << std::endl;
    return 0;
}
