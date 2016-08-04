//
//  main.cpp
//  Count and Say
//
//  Created by apple on 16/5/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string seq("1");
        for (int i = 1; i < n; i++) {
            stringstream ss;
            int count = 1;
            for (int pos = 1; pos < seq.length(); pos++) {
                if (seq[pos] == seq[pos - 1]) {
                    count++;
                }
                else {
                    ss << count << seq[pos - 1];
                    count = 1;
                }
            }
            ss << count << seq[seq.length() - 1];
            ss >> seq;
        }

        return seq;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    cout << s.countAndSay(6) << endl;
    cout << s.countAndSay(1) << endl;
    return 0;
}
