//
//  main.cpp
//  Summary Ranges
//
//  Created by apple on 15/12/28.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    vector<int> splitflags;
    if (nums.size() == 0) {
        return ranges;
    }
    splitflags.push_back(0);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - 1 != nums[i - 1]) splitflags.push_back(i);
    }
    splitflags.push_back(nums.size());
    
    for (int i = 0; i < splitflags.size() - 1; i++) {
        string range;
        stringstream out;
        if (splitflags[i + 1] - splitflags[i]  > 1) {
            out<<nums[splitflags[i]]<<"->"<<nums[splitflags[i + 1] - 1];
        }
        else {
            out <<nums[splitflags[i]];
        }
        out >> range;
        ranges.push_back(range);
    }
    return ranges;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {};
    vector<string> ranges = summaryRanges(nums);
    for (int i = 0; i < ranges.size(); i++) {
        cout << ranges[i] << endl;
    }
    return 0;
}
