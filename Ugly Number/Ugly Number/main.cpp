//
//  main.cpp
//  Ugly Number
//
//  Created by apple on 15/11/14.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

using namespace std;

bool isUgly(int num) {
    if (num == 1) {
        return true;
    }
    else if (num % 7 == 0 || num <= 0){
        return false;
    }
    
    if (num % 2 == 0 && isUgly(num / 2)) {
        return true;
    }
    
    if (num % 3 == 0 && isUgly(num / 3)) {
        return true;
    }
    
    if (num % 5 == 0 && isUgly(num / 5)) {
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    if (isUgly(1332185066)) {
        cout << "ugly" << endl;
    }
    else {
        cout << "not uglt" << endl;
    }
    return 0;
}
