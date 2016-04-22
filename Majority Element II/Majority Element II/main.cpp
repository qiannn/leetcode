//
//  main.cpp
//  Majority Element II
//
//  Created by apple on 15/12/31.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int majority1 = 0, count1 = 0;
    int majority2 = 0, count2 = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (count1 == 0) {
            majority1 = nums[i];
            count1++;
        }
        else if (majority1 == nums[i]) {
            count1++;
        }
        else if (count2 == 0) {
            majority2 = nums[i];
            count2++;
        }
        else if (majority2 == nums[i]) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (majority1 == nums[i]) count1++;
        else if(majority2 == nums[i]) count2++;
    }
    
    vector<int> answer;
    if (count1 > nums.size() / 3) answer.push_back(majority1);
    if (count2 > nums.size() / 3) answer.push_back(majority2);

    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {1,1,1,1,1,1,1,2,2,2,2,2,2,3,3};
    vector<int> ans = majorityElement(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
