//
//  main.cpp
//  Majority Element
//
//  Created by apple on 15/12/28.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int majority = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            majority = nums[i];
            count ++;
        }
        else if (majority == nums[i]) {
            count ++;
        }
        else {
            count --;
        }
    }
    
    count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == majority) count ++;
    }
    int frequency = nums.size() / 2;
    if (count > frequency) {
        return majority;
    }
    return majority;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {1,1,1,3,2,1};
    cout << majorityElement(nums) << endl;
    return 0;
}
