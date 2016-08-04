//
//  main.cpp
//  Insertion Sort List
//
//  Created by apple on 16/6/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newlist = new ListNode(-1);
        ListNode *p, *q = head;
        while (q) {
            ListNode *nextnode = q->next;
            p = newlist;
            while (p->next != NULL && p->next->val < q->val) {
                p = p->next;
            }
            q->next = p->next;
            p->next = q;
            q = nextnode;
        }
        
        return newlist->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    
    node1->next = node2;
    node2->next = node3;
    Solution s;
    ListNode *head = s.insertionSortList(node1);
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}
