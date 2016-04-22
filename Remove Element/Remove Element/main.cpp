//
//  main.cpp
//  Remove Element
//
//  Created by apple on 16/4/5.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0, q = nums.size() - 1;
        while (p <= q) {
            if (nums[p] == val) {
                int tmp = nums[q];
                nums[q] = nums[p];
                nums[p] = tmp;
                q--;
            }
            else {
                p++;
            }
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {};
    Solution s;
    cout << s.removeElement(nums, 2) << endl;
    return 0;
}
