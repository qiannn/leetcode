//
//  main.cpp
//  Maximum Product Subarray
//
//  Created by apple on 16/4/7.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int max = 0, min = 0, answer = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int maxi = max;
            max = std::max(nums[i], std::max(nums[i]*max, nums[i]*min));
            min = std::min(nums[i], std::min(nums[i]*maxi, nums[i]*min));
            if (max > answer)
                answer = max;
        }
        return answer;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {-1};
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}
