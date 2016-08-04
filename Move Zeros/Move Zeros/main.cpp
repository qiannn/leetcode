//
//  main.cpp
//  Move Zeros
//
//  Created by apple on 15/11/24.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int>& nums) {
    vector<int>::iterator iter;
    int count = 0;
    for (iter = nums.begin(); iter != nums.end(); iter++) {
        if (*iter == 0) {
            iter = nums.erase(iter);
            iter --;
            count ++;
        }
    }
    
    while (count --) {
        nums.push_back(0);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeros(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}
