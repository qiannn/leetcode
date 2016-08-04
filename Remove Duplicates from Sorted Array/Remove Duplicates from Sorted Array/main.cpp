//
//  main.cpp
//  Remove Duplicates from Sorted Array
//
//  Created by apple on 16/4/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
    */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int q = 1;
        for (int p = 1; p < nums.size(); p++) {
            if (nums[p - 1] != nums[p]) {
                nums[q++] = nums[p];
            }
        }
        nums.erase(nums.begin() + q, nums.end());
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {1,1,1,2,3,3,3,3};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
