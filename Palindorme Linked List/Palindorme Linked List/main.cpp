//
//  main.cpp
//  Palindorme Linked List
//
//  Created by apple on 15/12/22.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode* reverseList(ListNode* head) {
    ListNode *newlist = NULL;
    ListNode *p = head;
    
    while (p != NULL) {
        ListNode *nextnode = p->next;
        p->next = newlist;
        newlist = p;
        p = nextnode;
    }
    return newlist;
}

bool isPalindorme(ListNode* head) {
    ListNode *p = head;
    int length = 0;
    
    while (p != NULL) {
        p = p->next;
        length ++;
    }
    p = head;
    for (int i = 0; i < length / 2 - 1; i++) {
        p = p->next;
    }
    
    ListNode* rightlist = reverseList(p->next);
    p->next = NULL;
    p = head;
    for (int i = 0; i < length / 2; i++) {
        if (p->val != rightlist->val) {
            return false;
        }
        p = p->next;
        rightlist = rightlist->next;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(1);
    ListNode *node6 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
//    node5->next = node6;
//    ListNode *newlist = reverseList(node1);
//    while (newlist != NULL) {
//        std::cout << newlist->val << std::endl;
//        newlist = newlist->next;
//    }
    
    if (isPalindorme(node1)) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "ops" << std::endl;
    }
    return 0;
}
