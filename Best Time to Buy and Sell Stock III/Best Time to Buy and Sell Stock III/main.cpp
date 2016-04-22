//
//  main.cpp
//  Best Time to Buy and Sell Stock III
//
//  Created by apple on 16/2/15.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    vector<int> forwarddp;
    vector<int> backwarddp;
    
    forwarddp.push_back(0);
    int start = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] - prices[start] < forwarddp[i - 1]) {
            forwarddp.push_back(forwarddp[i - 1]);
        }
        else {
            forwarddp.push_back(prices[i] - prices[start]);
        }
        if (prices[i] < prices[start]) {
            start = i;
        }
    }
    
    backwarddp.push_back(0);
    int rstart = prices.size() - 1;
    for (int i = prices.size() - 2; i > -1; --i) {
        if (prices[rstart] - prices[i] < backwarddp[backwarddp.size() - 1]) {
            backwarddp.push_back(backwarddp[backwarddp.size() - 1]);
        }
        else {
            backwarddp.push_back(prices[rstart] - prices[i]);
        }
        if (prices[i] > prices[rstart]) {
            rstart = i;
        }
    }
    
    int max = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (forwarddp[i] + backwarddp[prices.size() - i - 1] > max) {
            max = forwarddp[i] + backwarddp[prices.size() - i - 1];
        }
    }
    
    return max;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> prices = {0,8,5,7,4,7};
    cout << maxProfit(prices) << endl;
    return 0;
}
