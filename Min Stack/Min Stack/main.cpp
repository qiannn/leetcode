//
//  main.cpp
//  Min Stack
//
//  Created by apple on 16/4/3.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>

using namespace std;

class MinStack {
public:
    void push(int x) {
        s.push(x);
        if (minstack.empty() || x <= minstack.top())
            minstack.push(x);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if (!minstack.empty() && top == minstack.top())
            minstack.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
private:
    stack<int> minstack;
    stack<int> s;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    MinStack s;
    s.push(3);
    s.push(6);
    s.push(1);
    cout << "top of stack " << s.top() << endl;
    cout << "min of stack " << s.getMin() << endl;
    s.pop();
    cout << "top after pop " << s.top() << endl;
    cout << "min after pop " << s.getMin() << endl;
    return 0;
}
