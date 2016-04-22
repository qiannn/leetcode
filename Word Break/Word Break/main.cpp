//
//  main.cpp
//  Word Break
//
//  Created by apple on 15/10/27.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(string s, unordered_set<string>& dict) {
    vector<bool> flag(s.length() + 1, false);
    flag[0] = true;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = i - 1; j > -1; j--) {
            if (flag[j] == true &&
                find(dict.begin(), dict.end(), s.substr(j, i - j)) != dict.end()) {
                flag[i] = true;
                break;
            }
        }
    }
    
    if (flag[s.length()] == true) {
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    string s = "leetcode";
    unordered_set<string> dictionary;
    dictionary.insert("leet");
    dictionary.insert("code");
    
    if (wordBreak(s, dictionary)) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    

    return 0;
}