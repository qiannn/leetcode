//
//  main.cpp
//  leetcode-83
//
//  Created by apple on 15/10/20.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){};
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* current = head;
    while (current != NULL) {
        ListNode* p = current->next;
        while (p != NULL && p->val == current->val) {
            p = p->next;
        }
        current->next = p;
        current = current->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(5);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    
    ListNode* cur = deleteDuplicates(head);
    ListNode* pre = cur;
    while (cur != NULL) {
        std::cout<<cur->val<<std::endl;
        pre = cur;
        cur = cur->next;
        delete pre;
    }
    return 0;
}
