//
//  main.cpp
//  Find the Duplicate Number
//
//  Created by apple on 16/1/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int mid = n / 2;
    int left = 1, right = n;
    while (left < right) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= left && nums[i] <= mid) count++;
        }
        if (count > mid - left + 1) {
            right = mid;
            mid = (left + right) / 2;
        }
        else {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }
    return mid;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {1,1,2,4,6,5,3};
    cout << findDuplicate(nums) << endl;
    return 0;
}
