//
//  main.cpp
//  Scramble String
//
//  Created by apple on 16/5/18.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /*
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
    */
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        bool res[len][len][len + 1];

        for (int z = 0; z < len + 1; z++) {
            for (int x = 0; x < len; x++) {
                for (int y = 0; y < len; y++) {
                    res[x][y][z] = false;
                }
            }
        }
        
        for (int x = 0; x < len; x++) {
            for (int y = 0; y < len; y++) {
                res[x][y][1] = s1[x] == s2[y];
            }
        }
        
        //x:s1 index, y:s2 index, z:substring length
        for (int z = 1; z < len + 1; z++) {
            for (int x = 0; x + z < len + 1; x++) {
                for (int y = 0; y + z < len + 1; y++) {
                    for (int i = 1; i < z; i++) {
                        res[x][y][z] =
                        (res[x][y][i] && res[x + i][y + i][z - i])||
                        (res[x][y + z - i][i] && res[x + i][y][z - i]);
                        if (res[x][y][z])
                            break;
                    }
                }
            }
        }
        return res[0][0][len];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    string s1 = "xstjzkfpkggnhjzkpfjoguxvkbuopi", s2 = "xbouipkvxugojfpkzjhnggkpfkzjts";
    //string s1 = "great", s2 = "rgtae";
    if (s.isScramble(s1, s2))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}
