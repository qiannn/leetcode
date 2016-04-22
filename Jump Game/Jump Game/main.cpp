//
//  main.cpp
//  Jump Game
//
//  Created by apple on 16/4/20.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (furthest < i)
                return false;
            else
                furthest = std::max(furthest, i + nums[i]);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {3,2,1,0,4};
    Solution s;
    cout << (s.canJump(nums) ? "yes" : "ops") << endl;
    return 0;
}
