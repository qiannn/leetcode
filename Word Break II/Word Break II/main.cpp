//
//  main.cpp
//  Word Break II
//
//  Created by apple on 15/10/21.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void breaks(  string s,
              unordered_set<string>& wordDict,
              vector<bool>& flag,
              int sindex,
              string sub,
              vector<string>& answer) {
    
    if (sindex == s.length()) {
        answer.push_back(sub);
    }
    for (int i = sindex; i < s.length(); i++) {
        string tem = s.substr(sindex, i - sindex + 1);
        if (flag[i + 1] == true &&
            find(wordDict.begin(), wordDict.end(), tem) != wordDict.end()) {
            
            if (sub != "") {
                tem = sub + " " + tem;
            }
            breaks(s, wordDict, flag, i + 1, tem, answer);
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict)
{
    vector<string> answer;
    vector<bool> flag(s.length() + 1, false);
    flag[0] = true;
    for (int i = 1; i <= s.length(); i++) {
        for (int j = i - 1; j > -1; j--) {
            if (flag[j] == true &&
                find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                flag[i] = true;
                break;
            }
        }
    }
    
    if (flag[s.length()] == true) {
        breaks(s, wordDict, flag, 0, "", answer);
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    string s = "catsanddog";
    unordered_set<string> dictionary;

    dictionary.insert("cat");
    dictionary.insert("cats");
    dictionary.insert("and");
    dictionary.insert("sand");
    dictionary.insert("dog");
    
    vector<string> ans = wordBreak(s, dictionary);
    vector<string>::iterator iter;
    for (iter = ans.begin(); iter != ans.end(); iter++) {
        cout<<*iter<<endl;
    }
    return 0;
}