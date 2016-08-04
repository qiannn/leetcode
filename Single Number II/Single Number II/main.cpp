//
//  main.cpp
//  Single Number II
//
//  Created by apple on 15/12/1.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
/*
int singleNumber(vector<int>& nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i = i + 3) {
        if (nums[i] != nums[i + 2]) {
            ans = nums[i];
            i++;
        }
    }
    
    return ans;
}
*/

/*
int singleNumber(vector<int>& nums) {
    int ans = 0;
    int count[32];
    int e = 1;
    
    for (int i = 0; i < 32; ++i) {
        count[i] = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if ((nums[j] & e) == e) {
                count[i] ++;
            }
        }
        ans += (count[i] % 3) * e;
        e = e << 1;
    }
    
    return ans;
}
*/

int singleNumber(vector<int>& nums) {
    int ans = 0;
    int a = 0, b = 0;
    
    for (int i = 0; i < nums.size(); ++i) {
        int tmp = a;
        a = (a&~b&~nums[i]) | (~a&b&nums[i]);
        b = (~tmp&b&~nums[i]) | (~tmp&~b&nums[i]);
    }
    ans = ~a&b;
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    std::cout << "Hello, World!\n";
    cout << singleNumber(nums) << endl;
    return 0;
}
