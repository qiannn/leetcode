//
//  main.cpp
//  Sort List
//
//  Created by apple on 16/5/21.
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
    ListNode* sortList(ListNode* head) {
        if (!head)
            return head;
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head) {
        if (!head->next)
            return head;
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        ListNode* p = head;
        while (p->next != slow) {
            p = p->next;
        }
        p->next = NULL;
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(slow);
        ListNode* newlist = merge(l1, l2);
        return newlist;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head, *end, *p = l1, *q = l2;
        if (p->val < q->val) {
            head = end = p;
            p = p->next;
        }
        else {
            head = end = q;
            q = q->next;
        }
        
        while (p && q) {
            if (p->val < q->val) {
                end->next = p;
                p = p->next;
            }
            else {
                end->next = q;
                q = q->next;
            }
            end = end->next;
        }
        if (p) {
            end->next = p;
        }
        if (q) {
            end->next = q;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(6);
    ListNode* node2 = new ListNode(5);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(7);
    ListNode* node5 = new ListNode(2);
    ListNode* node6 = new ListNode(1);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    
    Solution s;
    ListNode* sortlist = s.sortList(node1);
    while (sortlist) {
        std::cout << sortlist->val << " " ;
        sortlist = sortlist->next;
    }
    std::cout << std::endl;
    return 0;
}
