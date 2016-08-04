//
//  main.cpp
//  Gas Station
//
//  Created by apple on 15/11/30.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<int> gain;
    int n = gas.size();
    int sum = 0;
    int start = 0;
    int end = 0;
    
    for (int i = 0; i < n; i++) {
        gain.push_back(gas[i] - cost[i]);
        sum += gas[i] - cost[i];
    }
    
    if (sum < 0) {
        return -1;
    }
    else {
        sum = 0;
    }
    
    while (start < n) {
        if (end - start == n - 1 && sum >= 0) {
            return start;
        }
        
        if (sum + gain[end % n] < 0) {
            sum -= gain[start];
            start ++;
        }
        else {
            sum += gain[end % n];
            end ++;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> gas = {2, 5};
    vector<int> cost = {3, 4};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
