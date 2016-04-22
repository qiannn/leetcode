//
//  main.cpp
//  Longest Increasing Subsequence
//
//  Created by apple on 16/3/28.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int maxlen = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxlen)
                maxlen = dp[i];
        }
        
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solution;
    //vector<int> nums = {10,9,2,5,3,7,101,18};
    //vector<int> nums = {10,9,2,5,3,4};
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout << solution.lengthOfLIS(nums) <<endl;
    return 0;
}
