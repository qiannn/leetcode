//
//  main.cpp
//  Climbing Stairs
//
//  Created by apple on 16/1/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>

int climbStairs(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << climbStairs(44) << std::endl;
    return 0;
}
