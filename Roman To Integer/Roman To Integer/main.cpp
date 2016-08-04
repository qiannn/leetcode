//
//  main.cpp
//  Roman To Integer
//
//  Created by apple on 15/12/3.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int alphabet(string s) {
    int number = 0;

    if (s == "IV") {
        number = 4;
    }
    if (s == "IX") {
        number = 9;
    }
    if (s == "XL") {
        number = 40;
    }
    if (s == "XC") {
        number = 90;
    }
    if (s == "CD") {
        number = 400;
    }
    if (s == "CM") {
        number = 900;
    }
    if (s == "I") {
        number = 1;
    }
    if (s == "V") {
        number = 5;
    }
    if (s == "X") {
        number = 10;
    }
    if (s == "L") {
        number = 50;
    }
    if (s == "C") {
        number = 100;
    }
    if (s == "D") {
        number = 500;
    }
    if (s == "M") {
        number = 1000;
    }
    return number;
}

int romanToInt(string s) {
    int ans = 0;
    if (s.length() < 2) {
        return alphabet(s);
    }
    string front = s.substr(0, 2);
    string back = "";
    if (alphabet(front) != 0) {
        back = s.substr(2);
    }
    else {
        front = s.substr(0, 1);
        back = s.substr(1);
    }
    
    ans = alphabet(front) + romanToInt(back);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << romanToInt("DCXXI") << endl;
    return 0;
}
