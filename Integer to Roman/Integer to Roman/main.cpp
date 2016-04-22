//
//  main.cpp
//  Integer to Roman
//
//  Created by apple on 15/12/2.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    string roman;
    int highdigit = 0;
    int digitlength = 1;
    int tmp = num;
    
    while (tmp / 10) {
        tmp /= 10;
        digitlength *= 10;
    }
    highdigit = tmp;
    
    if (num % digitlength == 0) {
        if (highdigit % 5 == 4) {
            return intToRoman(digitlength)+intToRoman(num+digitlength);
        }
        else if (highdigit % 5 == 0){
            if (digitlength == 1) {
                return "V";
            }
            if (digitlength == 10) {
                return "L";
            }
            if (digitlength == 100) {
                return "D";
            }
        }
        else {
            string romannumber;
            if (digitlength == 1) {
                romannumber = "I";
            }
            if (digitlength == 10) {
                romannumber = "X";
            }
            if (digitlength == 100) {
                romannumber = "C";
            }
            if (digitlength == 1000) {
                romannumber = "M";
            }
            
            if (highdigit > 5) {
                roman = intToRoman(5 * digitlength);
            }
            
            for (int i = 0; i < (highdigit % 5); i ++) {
                roman += romannumber;
            }
            return roman;
        }
    }
    
    roman = intToRoman(highdigit * digitlength) + intToRoman(num - highdigit * digitlength);
    
    return roman;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << intToRoman(1984) << endl;
    
    return 0;
}
