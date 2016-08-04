//
//  main.cpp
//  Valid Parentheses
//
//  Created by apple on 15/11/16.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> previous;
    
    if (s.size() < 2) {
        return false;
    }
    else {
        previous.push(s[0]);
    }
    
    int i = 1;
    while (i < s.size()) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            previous.push(s[i]);
        }
        else {
            char cur = '*';
            if (previous.empty()) {
                return false;
            }
            else {
                cur = previous.top();
            }
            
            switch (s[i]) {
                case ')': {
                    if (cur == '(') {
                        previous.pop();
                    }
                    else {
                        return false;
                    }
                }
                    break;
                case ']': {
                    if (cur == '[') {
                        previous.pop();
                    }
                    else {
                        return false;
                    }
                }
                    break;
                case '}': {
                    if (cur == '{') {
                        previous.pop();
                    }
                    else {
                        return false;
                    }
                }
                    break;
                default:
                    break;
            }
        }
        i++;
    }
    
    if (previous.empty()) {
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "[])";
    if (isValid(s)) {
        cout << "yep" << endl;
    }
    else {
        cout << "ops" << endl;
    }
    return 0;
}
