//
//  main.cpp
//  Find Minimum in Rotated Sorted Array II
//
//  Created by apple on 16/6/19.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    int helper(vector<int>& nums, int start, int end) {
        if (nums[start] < nums[end] || start == end) {
            return nums[start];
        }
        int mid = (start + end) / 2;
        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<int> nums = {1,2,0,1,1,1};
    cout << s.findMin(nums) << endl;
    return 0;
}
