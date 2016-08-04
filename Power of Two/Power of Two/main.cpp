//
//  main.cpp
//  Power of Two
//
//  Created by apple on 15/11/12.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    int a = 1;
    while (a <= n && a > 0) {
        if (a == n) {
            return true;
        }
        a = a * 2;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    if (isPowerOfTwo(1073741825)) {
        cout << "yes" << endl;
    }
    else {
        cout << "ops" << endl;
    }
    return 0;
}
