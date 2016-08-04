//
//  main.cpp
//  Group Anagrams
//
//  Created by apple on 15/12/27.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool less_lower(char x, char y) {
    return x < y;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> answer;
    map<string, vector<string>> anagrams;
    vector<string>::iterator iter = strs.begin();
    for (; iter != strs.end(); iter++) {
        string tmp = *iter;
        sort(tmp.begin(), tmp.end(), less_lower);
        anagrams[tmp].push_back(*iter);
    }
    
    map<string, vector<string>>::iterator map_iter = anagrams.begin();
    for (; map_iter != anagrams.end(); map_iter++) {
        sort(map_iter->second.begin(), map_iter->second.end());
        answer.push_back(map_iter->second);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> answer = groupAnagrams(strs);
    for (int i = 0; i < answer.size(); i++) {
        sort(answer[i].begin(), answer[i].end());
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
