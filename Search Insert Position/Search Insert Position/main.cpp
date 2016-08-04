//
//  main.cpp
//  Search Insert Position
//
//  Created by apple on 16/4/7.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int position = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target)
                return position;
            position++;
        }
        return position;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<int> nums = {1,3,5,6};
    
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    cout << s.searchInsert(nums, 7) << endl;
    cout << s.searchInsert(nums, 0) << endl;
    return 0;
}
