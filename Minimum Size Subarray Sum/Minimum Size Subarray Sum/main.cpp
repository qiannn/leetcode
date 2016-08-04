//
//  main.cpp
//  Minimum Size Subarray Sum
//
//  Created by apple on 15/11/26.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int minlen = 0;
    int sum = 0;
    int p = 0;
    int q = 0;
    while (q < nums.size()) {
        if (sum + nums[q] < s) {
            sum += nums[q];
            q++;
        }
        else {
            if (minlen == 0 || q - p + 1 < minlen) {
                minlen = q - p + 1;
            }
            sum -= nums[p];
            p++;
        }
    }
    return minlen;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,4,5};
    std::cout << minSubArrayLen(11, a) << endl;
    return 0;
}
