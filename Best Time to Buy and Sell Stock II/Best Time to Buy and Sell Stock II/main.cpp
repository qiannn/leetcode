//
//  main.cpp
//  Best Time to Buy and Sell Stock II
//
//  Created by apple on 16/2/4.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int start = 0, end = 0, profit = 0, lastvalue = 0;
    prices.push_back(-1);
    while (end < prices.size()) {
        if (prices[end] < lastvalue)
        {
            if (start != end - 1) profit += lastvalue - prices[start];
            start = end;
        }
        lastvalue = prices[end];
        end ++;
    }
    return profit;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> prices = {1};
    cout << maxProfit(prices) << endl;
    return 0;
}
