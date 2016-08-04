//
//  main.cpp
//  Length of Last Word
//
//  Created by apple on 15/12/4.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int length = 0;
    
    int position = s.find_last_of(' ');
    
    if (position != -1) {
        string subs = s.substr(position + 1);
        length = subs.length();
        if (length == 0) {
            subs = s.substr(0, position);
            length = lengthOfLastWord(subs);
        }
    }
    else {
        return s.length();
    }
    
    return length;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout << lengthOfLastWord("hhh") << endl;
    return 0;
}
