//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by apple on 16/5/22.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    void helper(string s,vector<string>& v,vector<vector<string> >& vv) {
        if (s.empty()) {
            vv.push_back(v);
        }
        
        for (int len = 1; len <= s.length(); len++) {
            string sub = s.substr(0, len);
            if (isPalindrome(sub)) {
                vector<string> _v(v);
                _v.push_back(sub);
                helper(s.substr(len), _v, vv);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > answer;
        vector<string> v;
        helper(s, v, answer);
        return answer;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string str = "aabcbdfe";
    Solution s;
    auto vv = s.partition(str);
    for (auto i : vv) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
