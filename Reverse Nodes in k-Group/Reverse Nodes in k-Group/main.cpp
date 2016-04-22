//
//  main.cpp
//  Reverse Nodes in k-Group
//
//  Created by apple on 15/12/9.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL) {};
};

ListNode* createListHead(ListNode* head) {
    ListNode* p = head;
    ListNode* q = NULL;
    while (p != NULL) {
        ListNode* next = p->next;
        p->next = q;
        q = p;
        p = next;
    }
    return q;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* p = head;
    ListNode* rightlisthead = NULL;
    
    for (int i = 0; i < k - 1; i++) {
        if (p != NULL) {
            p = p->next;
        }
        else {
            return head;
        }
    }
    
    if (p != NULL) {
        rightlisthead = p->next;
        p->next = NULL;
    }
    else {
        return head;
    }

    
    ListNode* leftlisthead = createListHead(head);
    ListNode* q = leftlisthead;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = reverseKGroup(rightlisthead, k);
    
    return leftlisthead;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    ListNode* p = reverseKGroup(node1, 2);
    while (p != NULL) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    return 0;
}
