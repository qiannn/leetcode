//
//  main.cpp
//  Add Binary
//
//  Created by apple on 16/4/4.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        if (a.empty() || b.empty())
            return !a.empty() ? a : b;
        size_t length = a.length() > b.length() ? a.length():b.length();
        int lena = a.length(), lenb = b.length();
        int dif = abs(lena - lenb);
        string padding(dif, '0');
        if (a.length() > b.length()) {
            b = padding + b;
        }
        else {
            a = padding + a;
        }
        int carry = 0, sum = 0;
        for (int i = length - 1; i > -1; i--) {
            sum = ((a[i] - '0') + (b[i] - '0') + carry) % 2;
            carry = ((a[i] - '0') + (b[i] - '0') + carry) > 1 ? 1 : 0;
            answer.push_back(sum ? '1':'0');
        }
        if (carry)
            answer.push_back('1');
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    string a = "10101";
    string b = "100";
 
    return 0;
}
