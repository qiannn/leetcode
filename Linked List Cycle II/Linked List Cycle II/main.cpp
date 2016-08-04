//
//  main.cpp
//  Linked List Cycle II
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

ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    ListNode *fast = head, *slow = head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast) fast = fast->next;
        else break;
        slow = slow->next;
        if (fast == slow) {
            ListNode* p = head;
            while (p != slow) {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = NULL;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    ListNode *p = detectCycle(node1);
    if (p) std::cout << p->val << std::endl;
    else std::cout << "ops" << std::endl;
    return 0;
}
