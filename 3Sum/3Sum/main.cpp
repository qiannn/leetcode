//
//  main.cpp
//  3Sum
//
//  Created by apple on 16/2/16.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > twoSum(vector<int>& nums, int start, int end, int target) {
    vector<vector<int> > vv;
    int p = start, q = end;
    
    while (p < q) {
        if (nums[p] + nums[q] == target) {
            vector<int> v;
            v.push_back(-target);
            v.push_back(nums[p]);
            v.push_back(nums[q]);
            vv.push_back(v);
            while (p < end && nums[p] == nums[p + 1]) {
                p++;
            }
            p++;
            while (q > 0 && nums[q] == nums[q - 1]) {
                q--;
            }
            q--;
        }
        else if (nums[p] + nums[q] > target) {
            q--;
        }
        else {
            p++;
        }
    }
    
    return vv;
}

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > vv;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int target = -nums[i];
//        vector<vector<int> > answer = twoSum(nums, i + 1, nums.size() - 1, target);
//        vv.insert(vv.end(), answer.begin(), answer.end());
        int p = i + 1, q = nums.size() - 1;
        
        while (p < q) {
            if (nums[p] + nums[q] == target) {
                vector<int> v;
                v.push_back(-target);
                v.push_back(nums[p]);
                v.push_back(nums[q]);
                vv.push_back(v);
                while (p < nums.size() - 1 && nums[p] == nums[p + 1]) {
                    p++;
                }
                p++;
                while (q > i + 1 && nums[q] == nums[q - 1]) {
                    q--;
                }
                q--;
            }
            else if (nums[p] + nums[q] > target) {
                q--;
            }
            else {
                p++;
            }
        }
    }
    return vv;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<vector<int> > vv = threeSum(nums);//(nums, 0, nums.size(), 1);
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
