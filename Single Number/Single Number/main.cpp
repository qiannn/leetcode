//
//  main.cpp
//  Single Number
//
//  Created by apple on 15/11/26.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        ans ^= nums[i];
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3,4,3,2,1};
    std::cout << singleNumber(a) << endl;
    return 0;
}
