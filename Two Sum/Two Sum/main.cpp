//
//  main.cpp
//  Two Sum
//
//  Created by apple on 15/12/5.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int, vector<int>> hashtable;
    
    for (int i = 0; i < nums.size(); ++i) {
        hashtable[nums[i]].push_back(i);
    }
    
    for (int i = 0; i < nums.size(); ++i) {
        if (hashtable.find(target - nums[i]) != hashtable.end()) {
            for (int j = 0; j < hashtable[target-nums[i]].size(); ++j) {
                if (hashtable[target - nums[i]][j] > i) {
                    ans.push_back(i + 1);
                    ans.push_back(hashtable[target - nums[i]][j] + 1);
                }
            }
        }
    }
    
    return ans;
}
*/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int, int> hashtable;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (hashtable.find(nums[i]) == hashtable.end()) {
            hashtable[target - nums[i]] = i;
        }
        else {
            ans.push_back(hashtable[nums[i]] + 1);
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> nums = {2, 7, 13, 11};
    vector<int> answer = twoSum(nums, 9);
    cout << answer[0] << " " << answer[1] << endl;
    return 0;
}
