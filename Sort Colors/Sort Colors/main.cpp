//
//  main.cpp
//  Sort Colors
//
//  Created by apple on 16/5/27.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (auto i : nums) {
            if (i == 0) {
                red++;
            }
            if (i == 1) {
                white++;
            }
            if (i == 2) {
                blue++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < red) {
                nums[i] = 0;
            }
            if (i < red + white && i >= red) {
                nums[i] = 1;
            }
            if (i >= red + white) {
                nums[i] = 2;
            }
        }
    }
    */
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left++]);
            }
            if (nums[i] == 2) {
                swap(nums[i], nums[right--]);
                continue;
            }
            i++;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<int> nums = {1,0};
    s.sortColors(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
