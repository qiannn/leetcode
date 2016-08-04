//
//  main.cpp
//  Partition List
//
//  Created by apple on 16/4/4.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return NULL;
        ListNode *first = NULL, *second = NULL;
        ListNode *p = NULL, *q = NULL, *k = head;
        while (k) {
            if (k->val < x) {
                if (first) {
                    p->next = k;
                    p = p->next;
                }
                else {
                    first = k;
                    p = first;
                }
            }
            else {
                if (second) {
                    q->next = k;
                    q = q->next;
                }
                else {
                    second = k;
                    q = second;
                }
            }
            k = k->next;
        }
        if (second)
            q->next = NULL;
        if (!first) {
            return second;
        }
        p->next = second;
        return first;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(3);
    ListNode *node7 = new ListNode(2);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    
    Solution s;
    s.partition(node1, 9);
    ListNode *p = node1;
    
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    return 0;
}
