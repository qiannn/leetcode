//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by apple on 16/1/23.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int max_profit = 0;
    int dp = 0;
    int min_price = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] - min_price > dp) dp = prices[i] - min_price;
        if (dp > max_profit) max_profit = dp;
        if (prices[i] < min_price) min_price = prices[i];
    }
    return max_profit;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> prices = {2,1,2,0,1,9};
    cout << maxProfit(prices) << endl;
    return 0;
}
