//
//  main.cpp
//  Best Time to Buy and Sell Stock IV
//
//  Created by apple on 16/3/14.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int days = prices.size();
        if (days <= 1) return 0;
        
        if (k > days/2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        
        vector<vector<int> > dp(days, vector<int>(k + 1, 0));
        vector<vector<int> > local(days, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i < days; ++i) {
                int diff = prices[i] - prices[i-1];
                local[i][j] = max(dp[i-1][j-1] + max(diff, 0),
                                  local[i-1][j] + diff);
                dp[i][j] = max(dp[i-1][j], local[i][j]);
            }
        }
        return dp[days - 1][k];
    }
    
    int max(int x, int y) {
        return x > y ? x : y;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> prices = {6,1,3,2,4,7};
    //vector<int> prices = {2, 1};
    Solution solution;
    cout << solution.maxProfit(1, prices) << endl;
    
    return 0;
}
