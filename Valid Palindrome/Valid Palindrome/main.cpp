//
//  main.cpp
//  Valid Palindrome
//
//  Created by apple on 16/1/7.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string preOperate(string& s) {
    string ss;
    for (int i = 0; i < s.size(); i++) {
        if (::isalpha(s[i]) || ::isdigit(s[i])) {
            //ss.push_back(::tolower(s[i]));
            ss += ::tolower(s[i]);
        }
    }
    return ss;
}

bool isPalindrome(string s) {
    string ss = preOperate(s);
    int left = 0;
    int right = ss.size() - 1;
    while (left <= right) {
        if (ss[left] != ss[right]) {
            return false;
        }
        else {
            left ++;
            right --;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    if (isPalindrome("a.")) {
        cout << "yes" << endl;
    }
    else {
        cout << "ops" << endl;
    }
    return 0;
}
