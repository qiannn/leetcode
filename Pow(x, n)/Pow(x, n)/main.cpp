//
//  main.cpp
//  Pow(x, n)
//
//  Created by apple on 16/5/5.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        
        double answer = myPow(x, abs(n / 2));
        double _x;
        if (abs(n) % 2 == 1) {
            _x = x;
        }
        else {
            _x = 1.0;
        }
        
        if (n < 0) {
            return 1.0 / (answer * answer * _x);
        }
        return answer * answer * _x;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    std::cout << s.myPow(2.0, -3) << std::endl;
    std::cout << s.myPow(0.00001, 2147483647) << std::endl;
    return 0;
}
