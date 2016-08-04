//
//  main.cpp
//  Longest Common Prefix
//
//  Created by apple on 15/12/4.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";
    if (strs.size() == 0) {
        return prefix;
    }
    
    for (int i = 0; i < strs[0].size(); ++i) {
        char cur = strs[0][i];
        for (int j = 0; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != cur) {
                return prefix;
            }
        }
        prefix.push_back(cur);
    }
    
    return prefix;
}

/*
string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";
    if (strs.size() == 0) {
        return prefix;
    }
    sort(strs.begin(), strs.end());
    if (strs.size() == 1) {
        prefix = strs[0];
    }
    else {
        int i = 0;
        if (strs[0].size() > 0)
        {
            while (i < strs[0].size() && strs[0][i] == strs[1][i]) {
                prefix.push_back(strs[0][i]);
                i++;
            }
        }
    }
    return prefix;
}
*/

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> strs = {"a"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
