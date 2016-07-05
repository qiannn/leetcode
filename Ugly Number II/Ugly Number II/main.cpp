//
//  main.cpp
//  Ugly Number II
//
//  Created by apple on 16/7/4.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int x, int y, int z) {
        int minNum = x < y ? x : y;
        minNum = minNum < z ? minNum : z;
        return minNum;
    }
    
    int nthUglyNumber(int n) {
        int minUglyNumber = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);
        for (int i = 0; i < n - 1; i++) {
            minUglyNumber = min(uglyNumbers[p2] * 2,
                                uglyNumbers[p3] * 3,
                                uglyNumbers[p5] * 5);
            uglyNumbers.push_back(minUglyNumber);
            if (minUglyNumber == uglyNumbers[p2] * 2) {
                p2++;
            }
            if (minUglyNumber == uglyNumbers[p3] * 3) {
                p3++;
            }
            if (minUglyNumber == uglyNumbers[p5] * 5) {
                p5++;
            }
        }
        return minUglyNumber;
    }
    
    /*
    int nthUglyNumber(int n) {
        int minUglyNumber = 1;
        queue<int> queue1, queue2, queue3;
        queue1.push(1);
        for (int i = 0; i < n - 1; i++) {
            int q1 = queue1.empty() ? INT_MAX : queue1.front() * 2;
            int q2 = queue2.empty() ? INT_MAX : queue2.front() * 3;
            int q3 = queue3.empty() ? INT_MAX : queue3.front() * 5;
            
            minUglyNumber = min(q1, q2, q3);
            queue1.push(minUglyNumber);
            
            if (minUglyNumber == q1 && !queue1.empty()) {
                queue1.pop();
                queue2.push(q1 / 2);
            }
            if (minUglyNumber == q2 && !queue2.empty()) {
                queue2.pop();
                queue3.push(q2 / 3);
            }
            if (minUglyNumber == q3 && !queue3.empty()) {
                queue3.pop();
            }
        }
        return minUglyNumber;
    }
    */
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    cout << s.nthUglyNumber(1500) << endl;
    return 0;
}
