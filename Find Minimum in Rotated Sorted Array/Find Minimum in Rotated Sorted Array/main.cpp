//
//  main.cpp
//  Find Minimum in Rotated Sorted Array
//
//  Created by apple on 15/10/29.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void sub(int start, int end, vector<int>& nums, int& p) {
    int mid = (start + end) / 2;
    if (start > end) {
        return;
    }
    
    if (mid == nums.size() - 1 && nums[mid - 1] > nums[mid]) {
        p = mid;
        return;
    }
    
    if (mid == 0) {
        sub(mid + 1, end, nums, p);
    }
    else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) {
        p = mid;
    }
    else {
        sub(start, mid - 1,nums, p);
        sub(mid + 1, end, nums, p);
    }
}

int findMin(vector<int>& nums) {
    int p = 0;
    sub(0, nums.size() - 1, nums, p);
    return nums[p];
}

int main(int argc, const char * argv[]) {
    int example[] = {1};
    vector<int> nums(example, example + 1);
    cout<<findMin(nums)<<endl;
    return 0;
}
