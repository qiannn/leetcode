//
//  main.cpp
//  Largest Rectangle in Histogram
//
//  Created by apple on 16/5/28.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        heights.push_back(0);
        stack<int> s;
        for (int i = 0; i < heights.size();) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i++);
            }
            else {
                int index = s.top();
                s.pop();
                int area;
                if (!s.empty())
                    area = heights[index] * (i - s.top() - 1);
                else
                    area = heights[index] * i;
                largestArea = largestArea < area ? area : largestArea;
            }
        }
        return largestArea;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> heights = {4,2,0,3,2,5};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
