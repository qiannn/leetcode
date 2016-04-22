//
//  main.cpp
//  Gray Code
//
//  Created by apple on 16/1/11.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) {
    vector<int> gray;
    if (n < 0) return gray;
    if (n == 0) {
        gray.push_back(0);
        return gray;
    }
    
    gray = grayCode(n - 1);
    int tmp = 1 << (n - 1);
    for (int i = gray.size() - 1; i > -1 ; i--) {
        gray.push_back(gray[i] + tmp);
    }
    return gray;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> gray = grayCode(2);
    for (int i = 0; i < gray.size(); i++) {
        std::cout << gray[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
