//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by apple on 16/5/21.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int maxlen = 1, start = 0;
        unordered_map<char, int> char_map;
        //char_map[s[start]] = start;
        for (int p = 0; p < s.length(); p++) {
            char cur_char = s[p];
            auto repeatchar_iter = char_map.find(cur_char);
            if (repeatchar_iter != char_map.end()) {
                start = max(repeatchar_iter->second + 1, start);
            }
            char_map[cur_char] = p;
            maxlen = max(p - start + 1, maxlen);
        }
        
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    //3
    string s1("abcabcbb");
    //1
    string s2("bbbbb");
    //3
    string s3("pwwkew");
    //13
    string s4("tdknvjqvwrsvehvkheyooqegdkipsirnnbakmsfijyeoh");
    
    //cout << s.lengthOfLongestSubstring(s1) << endl;
    //cout << s.lengthOfLongestSubstring(s2) << endl;
    
    //cout << s.lengthOfLongestSubstring(s3) << endl;
    cout << s.lengthOfLongestSubstring(s4) << endl;
    //11
    cout << s.lengthOfLongestSubstring("vaewogmglhxqbyqkdlaxuqyztrrksuenwkmkryrefqvions") << endl;
    //3
    //cout << s.lengthOfLongestSubstring("abc") << endl;
    
    return 0;
}
