//
//  main.cpp
//  4Sum
//
//  Created by apple on 16/2/16.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int> > vv;
    if (nums.size() == 4) {
        int sum = 0;
        for (int i = 0; i < 4; ++i) {
            sum += nums[i];
        }
        if (sum == target) {
            vv.push_back(nums);
            return vv;
        }
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int threesum_target = target - nums[i];
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            
            int twosum_target = threesum_target - nums[j];
            int p = j + 1, q = nums.size() - 1;
            while (p < q)
            {
                if (nums[p] + nums[q] == twosum_target)
                {
                    std::vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
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
                else if (nums[p] + nums[q] > twosum_target)
                {
                    q--;
                }
                else 
                {
                    p++;
                }
            }
        }
    }
    return vv;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v = {-1,-5,-5,-3,2,5,0,4};
    vector<vector<int> > vv = fourSum(v, -7);
    for (int i = 0; i < vv.size(); ++i)
    {
        for (int j = 0; j < vv[i].size(); ++j)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
