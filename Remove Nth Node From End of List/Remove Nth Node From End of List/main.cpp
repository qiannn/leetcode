//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by apple on 16/4/24.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* firstp = head;
        ListNode* secondp = head;
        while (firstp->next != NULL) {
            firstp = firstp->next;
            if (n == 0)
                secondp = secondp->next;
            else
                n--;
        }
        
        //seconddp is the point should be removed
        if (secondp == head && n != 0)
            head = head->next;
        else
            secondp->next = secondp->next->next;

        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    
    //node1->next = node2;
    //node2->next = node3;
    //node3->next = node4;
    //node4->next = node5;
    
    ListNode* node = new ListNode(1);
    Solution s;
    ListNode* answer = s.removeNthFromEnd(node1, 1);
    while (answer != NULL) {
        std::cout << answer->val << " " << std::endl;
        answer = answer->next;
    }
    return 0;
}
