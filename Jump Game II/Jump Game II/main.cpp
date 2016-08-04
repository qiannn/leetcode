//
//  main.cpp
//  Jump Game II
//
//  Created by apple on 16/4/23.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int furthest = 0, flag = -1, step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > flag) {
                flag = furthest;
                step++;
            }
            furthest = max(furthest, i + nums[i]);
            if (furthest >= nums.size() - 1)
                return step;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {2,3,1,1,4};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}
