//
//  main.cpp
//  Divide Two Integers
//
//  Created by apple on 16/1/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend >= 0 ? dividend : -(long long) dividend;
        long long b = divisor >= 0 ? divisor : -(long long) divisor;
        long long result = 0, shift = 31;
        while (shift >= 0) {
            if (a >= b << shift) {
                a -= b << shift;
                result += 1LL << shift;
            }
            shift--;
        }
        result = ((dividend ^ divisor) >> 31) ? (-result) : (result);
        if (result > INT32_MAX) return INT32_MAX;
        else return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
