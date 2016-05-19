//
//  main.cpp
//  Scramble String
//
//  Created by apple on 16/5/18.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        
        string ss1 = s1;
        string ss2 = s2;
        
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1 != ss2)
            return false;
        
        for (int i = 1; i < s1.length(); i++) {
            string left_subs1 = s1.substr(0, i);
            string right_subs1 = s1.substr(i);
            bool flag1 = isScramble(left_subs1, s2.substr(0, i)) &&
            isScramble(right_subs1, s2.substr(i));
            bool flag2 = isScramble(left_subs1, s2.substr(s2.length() - i)) &&
            isScramble(right_subs1, s2.substr(0, s2.length() - i));
                       
            if (flag1 || flag2)
                return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    if (s.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}
