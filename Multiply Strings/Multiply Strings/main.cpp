//
//  main.cpp
//  Multiply Strings
//
//  Created by apple on 15/12/12.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string add(string num1, string num2) {
    if (num1.length() < num2.length()) {
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    int i, j;
    for (i = num1.length() - 1, j = num2.length() - 1; i >= 0; i--, j--) {
        num1[i] = (num1[i] + (j >= 0 ? num2[j] - '0' : 0));
        if (num1[i] > '9') {
            num1[i] -= 10;
            if (i != 0) {
                num1[i - 1]++;
            }
            else {
                num1 = '1' + num1;
            }
        }
    }
    return num1;
}

string sub(string num1, string num2) {
    string sign = "";
    if (num1.length() == num2.length()) {
        if (num1 == num2) {
            return "0";
        }
        else if (num1 < num2) {
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
            sign = "-";
        }
    }
    else if (num1.length() < num2.length()) {
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
        sign = "-";
    }
    int i, j;
    for (i = num1.length() - 1, j = num2.length() - 1; i >= 0; i--, j--) {
        num1[i] = (num1[i] - (j >= 0 ? num2[j] - '0' : 0));
        if (num1[i] < '0') {
            num1[i] += 10;
            if (i != 0) {
                num1[i - 1]--;
            }
        }
    }
    return sign + num1;
}

string multiply(string num1, string num2) {
    string answer;
    vector<int> lnum;
    vector<int> rnum;
    vector<int> result;
    
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    
    result.push_back(0);
    
    for (int i = num1.size() - 1; i > -1; i--) {
        lnum.push_back(num1[i] - '0');
    }
    
    for (int i = num2.size() - 1; i > -1; i--) {
        rnum.push_back(num2[i] - '0');
    }
    
    for (int i = 0; i < rnum.size(); i++) {
        int multiplycarry = 0;
        int addcarry = 0;
        for (int j = 0; j < lnum.size(); j++) {
            int tmp = rnum[i] * lnum[j] + multiplycarry;
            if (tmp > 9) {
                multiplycarry = tmp / 10;
                tmp = tmp % 10;
            }
            else {
                multiplycarry = 0;
            }
            
            if (i + j > result.size() - 1) {
                if (tmp + addcarry > 9) {
                    result.push_back((tmp + addcarry) % 10);
                    addcarry = (tmp + addcarry) / 10;
                }
                else {
                    result.push_back(tmp + addcarry);
                    addcarry = 0;
                }
            }
            else {
                int old = result[i + j];
                if (old + tmp + addcarry > 9) {
                    result[i + j] = (old + tmp + addcarry) % 10;
                    addcarry = (old + tmp + addcarry) / 10;
                }
                else {
                    result[i + j] = old + tmp + addcarry;
                    addcarry = 0;
                }
            }
        }
        
        if (multiplycarry + addcarry > 9) {
            result.push_back((multiplycarry + addcarry) % 10);
            result.push_back((multiplycarry + addcarry) / 10);
        }
        else if (addcarry + multiplycarry != 0){
            result.push_back(addcarry + multiplycarry);
        }
    }
    
    for (int i = result.size() - 1; i > -1; i--) {
        answer.push_back('0' + result[i]);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << multiply("408", "0") << endl;
    cout << sub("555", "1000") << endl;
    return 0;
}
