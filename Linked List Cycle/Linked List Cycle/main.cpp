//
//  main.cpp
//  Linked List Cycle
//
//  Created by apple on 16/1/10.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};

bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode *fast = head->next, *slow = head;
    while (fast != NULL) {
        if (fast == slow) return true;
        fast = fast->next;
        if (fast) fast = fast->next;
        slow = slow->next;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = NULL;
    node3->next = NULL;
    if (hasCycle(node1)) std::cout << "yes" << std::endl;
    else std::cout << "ops" << std::endl;
    return 0;
}
