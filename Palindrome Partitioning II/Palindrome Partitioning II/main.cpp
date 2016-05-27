//
//  main.cpp
//  Palindrome Partitioning II
//
//  Created by apple on 16/5/22.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        int dp[len + 1];
        bool isPalindrome[len][len];
        
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
            if (i + 1 < len) {
                isPalindrome[i][i + 1] = s[i] == s[i + 1];
            }
        }
        
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 2; j < len; j++) {
                isPalindrome[i][j] = (s[i] == s[j]) &&
                                      isPalindrome[i + 1][j - 1];
            }
        }
        
        dp[0] = -1;
        for (int i = 1; i <= len; i++) {
            dp[i] = i - 1;
            for (int j = 0; j < i; j++) {
                if (isPalindrome[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[len];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    cout << s.minCut("aa") << endl;
    return 0;
}
