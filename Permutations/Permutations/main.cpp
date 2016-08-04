//
//  main.cpp
//  Permutations
//
//  Created by apple on 16/4/27.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > answer;
        if (nums.empty())
            return answer;
        sort(nums.begin(), nums.end());
        answer.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
            answer.push_back(nums);
        return answer;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector< vector<int> > permutation;
    Solution s;
    vector<int> nums = {0,1,-1};
    permutation = s.permute(nums);
    
    for (int i = 0; i < permutation.size(); i++) {
        for (int j = 0; j < permutation[i].size(); j++) {
            cout << permutation[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
