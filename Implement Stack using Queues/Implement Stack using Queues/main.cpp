//
//  main.cpp
//  Implement Stack using Queues
//
//  Created by apple on 16/1/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

class Stack {
public:
    void push(int x) {
        m_deque.push_back(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        m_deque.pop_back();
    }
    
    // Get the top element.
    int top() {
        return m_deque.back();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return m_deque.empty();
    }
    
private:
    deque<int> m_deque;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Stack s;
    for (int i = 0; i < 100; i++) {
        s.push(i);
    }
    while (!s.empty()) {
        int n = s.top();
        s.pop();
        cout << n << endl;
    }
    return 0;
}
