//
//  main.cpp
//  Combinations
//
//  Created by apple on 16/4/5.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > combinations;
        if (k > n)
            return combinations;
        vector<int> v;
        helper(1, n, k, v, combinations);
        return combinations;
    }
    void helper(int start, int n, int k,
                vector<int> &v, vector<vector<int> > &vv) {
        if (k == 0) {
            vv.push_back(v);
            return;
        }
        for (int i = start; i <= n; i++) {
            //vector<int> vi(v);
            v.push_back(i);
            helper(i + 1, n, k - 1, v, vv);
            v.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    vector<vector<int> > answer = s.combine(4, 2);
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
