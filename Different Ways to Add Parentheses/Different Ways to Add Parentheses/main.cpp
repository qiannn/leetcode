//
//  main.cpp
//  Different Ways to Add Parentheses
//
//  Created by apple on 15/11/11.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> ans;
    bool isoperator = false;
    
    for (int i = 0; i < input.size(); i ++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            isoperator = true;
            string left = input.substr(0, i);
            string right = input.substr(i + 1, input.size() - i - 1);
            char oper = input.at(i);
        
            vector<int> leftresult = diffWaysToCompute(left);
            vector<int> rightresult = diffWaysToCompute(right);
        
            for (int i = 0; i < leftresult.size(); i ++) {
                for (int j = 0; j < rightresult.size(); j++) {
                    if(oper == '+') {
                        ans.push_back(leftresult[i] + rightresult[j]);
                    }
                
                    if(oper == '-') {
                        ans.push_back(leftresult[i] - rightresult[j]);
                    }
                
                    if (oper == '*') {
                        ans.push_back(leftresult[i] * rightresult[j]);
                    }
                }
            }
        }
    }
    
    if (!isoperator) {
        ans.push_back(atoi(input.c_str()));
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    string expression = "2*3-4*5";
    vector<int> ans = diffWaysToCompute(expression);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
