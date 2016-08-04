//
//  main.cpp
//  Copy List with Random Pointer
//
//  Created by apple on 15/12/17.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x):label(x), next(NULL), random(NULL) {};
};

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* newlist = NULL;
    if (head != NULL) {
        newlist = new RandomListNode(head->label);
    }
    else {
        return NULL;
    }
    
    map<RandomListNode*, RandomListNode*> hashtable;
    hashtable.insert(pair<RandomListNode*, RandomListNode*>
                     (head, newlist));
    RandomListNode* p = head->next;
    RandomListNode* q = newlist;
    while (p != NULL) {
        RandomListNode* newnode = new RandomListNode(p->label);
        hashtable.insert(pair<RandomListNode*, RandomListNode*>
                         (p,newnode));
        p = p->next;
        q->next = newnode;
        q = q->next;
    }
    
    p = head;
    q = newlist;
    
    while (p != NULL && q != NULL) {
        q->random = hashtable[p->random];
        p = p->next;
        q = q->next;
    }
    
    return newlist;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    RandomListNode* node4 = new RandomListNode(4);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    node1->random = node3;
    node2->random = node1;
    node3->random = node2;
    node4->random = node1;
    
    RandomListNode* newlist = copyRandomList(node1);
    while (newlist != NULL) {
        std::cout << newlist->random->label;
        newlist = newlist->next;
    }
    std::cout << endl;
    return 0;
}
