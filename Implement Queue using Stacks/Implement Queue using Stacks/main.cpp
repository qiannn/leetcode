//
//  main.cpp
//  Implement Queue using Stacks
//
//  Created by apple on 16/6/17.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        pushStack.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if (popStack.empty())
            helper();
        popStack.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if (popStack.empty())
            helper();
        return popStack.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return pushStack.empty() && popStack.empty();
    }
private:
    void helper() {
        while (!pushStack.empty()) {
            int x = pushStack.top();
            pushStack.pop();
            popStack.push(x);
        }
    };
    stack<int> pushStack;
    stack<int> popStack;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    cout << queue.peek() << endl;
    queue.pop();
    cout << queue.peek() << endl;
    queue.pop();
    cout << queue.peek() << endl;
    queue.pop();
    
    return 0;
}
