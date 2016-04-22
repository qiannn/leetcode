//
//  main.cpp
//  Factorial Trailing Zeroes
//
//  Created by apple on 15/11/26.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

int trailingZeros(int n) {
    int count = 0;
    while (n) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::cout << trailingZeros(2147483647) << std::endl;
    return 0;
}
