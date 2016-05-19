//
//  main.cpp
//  First Missing Positive
//
//  Created by apple on 16/5/20.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;
        for (int i = 0; i < nums.size();) {
            //cout << "i:" << i << endl;
            //cout << "nums[i]:" << nums[i] << endl;
            if (!(nums[i] == i + 1 || nums[i] < 1 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
                i++;
        }
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    //vector<int> nums = {1,0};
    //vector<int> nums = {1,1};
    //vector<int> nums = {3,4,-1,1};
    vector<int> nums = {100,200,300};
    //vector<int> nums = {10,4,16,54,17,-7,21,15,25,31,61,1,6,12,21,46,16,56,54,12,23,20,38,63,2,27,35,11,13,47,13,11,61,39,0,14,42,8,16,54,50,12,-10,43,11,-1,24,38,-10,13,60,0,44,11,50,33,48,20,31,-4,2,54,-6,51,6};
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
