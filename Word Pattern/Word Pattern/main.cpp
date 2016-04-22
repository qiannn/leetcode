//
//  main.cpp
//  Word Pattern
//
//  Created by apple on 15/10/31.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool wordPattern(string pattern, string str) {
    int p = 0;
    int count = 0;
    int flag = 0;
    vector<string> words;
    while (p != str.length()) {
        if (str[p] == ' ') {
            count++;
            string word = str.substr(flag, p - flag);
            words.push_back(word);
            flag = p + 1;
        }
        p++;
    }
    string word = str.substr(flag, str.length() - flag + 1);
    words.push_back(word);
    
    if (count != pattern.length() - 1) {
        return false;
    }
    
    map<char, string> dic1;
    map<string, char> dic2;
    int i = 0;
    while (i != pattern.length()) {
        if (dic1.find(pattern[i]) == dic1.end()) {
            dic1[pattern[i]] = words[i];
        }
        else if (dic1[pattern[i]] != words[i]) {
            return false;
        }
        
        if (dic2.find(words[i]) == dic2.end()) {
            dic2[words[i]] = pattern[i];
        }
        else if (dic2[words[i]] != pattern[i]) {
            return false;
        }
        i++;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    string pattern = "abba";
    string str = "dog dog dog dog";
    
    if (wordPattern(pattern, str)) {
        cout << "yes" << endl;
    }
    else {
        cout << "ops" << endl;
    }
    return 0;
}
