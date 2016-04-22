//
//  main.cpp
//  Generate Parentheses
//
//  Created by apple on 16/1/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;

void generator(string str, int left, int right, int end) {
    if (left == end && right == end) {
        result.push_back(str);
        return;
    }
    if (left != end) generator(str + "(", left + 1, right, end);
    if (right < left) generator(str + ")", left, right + 1, end);
}

vector<string> generateParenthesis(int n) {
    generator("", 0, 0, n);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> result;
    result = generateParenthesis(3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
