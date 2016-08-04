//
//  main.cpp
//  Maximum Subarray
//
//  Created by apple on 16/4/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int global = nums[0];
        int local  = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            local = max(local + nums[i], nums[i]);
            global = max(local, global);
        }
        return global;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
