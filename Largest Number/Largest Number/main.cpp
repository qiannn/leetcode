//
//  main.cpp
//  Largest Number
//
//  Created by apple on 15/11/4.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool func(int x, int y) {
    string a = to_string(x), b = to_string(y);

    return a + b > b + a ? true : false;
}

string largestNumber(vector<int>& nums) {
    string answer = "";
    if (nums.size() > 1) {
        sort(nums.begin(), nums.end(), func);
    }
    
    vector<int>::iterator iter;
    for (iter = nums.begin();iter != nums.end(); iter++) {
        
        answer += to_string(*iter);
    }
    
    if (answer[0] == '0') {
        return "0";
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {0, 0};
    
    cout << largestNumber(nums) << endl;
    
    return 0;
}
