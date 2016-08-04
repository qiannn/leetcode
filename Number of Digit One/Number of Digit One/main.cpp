//
//  main.cpp
//  Number of Digit One
//
//  Created by apple on 15/11/12.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

int countDigitOne(int n) {
    int count = 0;
    int e = 1;
    
    if (n <= 0) {
        return 0;
    }
    else if (n < 10) {
        return 1;
    }

    while (n / e >= 10) {
        e *= 10;
    }
    
    int highdigit = n / e;
 
    if (highdigit != 1) {
        count = highdigit * countDigitOne(e - 1) + e + countDigitOne(n - highdigit * e);
    }
    else if (highdigit == 1) {
        count = countDigitOne(e - 1) + (n - (e - 1)) + countDigitOne(n - highdigit * e);
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << countDigitOne(13) << std::endl;
    return 0;
}
