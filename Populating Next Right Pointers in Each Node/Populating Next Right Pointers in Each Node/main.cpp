//
//  main.cpp
//  Populating Next Right Pointers in Each Node
//
//  Created by apple on 15/10/30.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if (root == NULL || root->left == NULL) {
        return;
    }
    queue<TreeLinkNode*> q;
    int count = 1;
    int height = 0;
    q.push(root);
    
    while (!q.empty()) {
        TreeLinkNode *currentnode = q.front();
        q.pop();
        //check and add next right pointer;
        count --;
        
        if (count == 0) {
            currentnode->next = NULL;
            count = pow(2, ++height);
        }
        else {
            currentnode->next = q.front();
        }
        
        if (currentnode->left != NULL && currentnode->right != NULL) {
            q.push(currentnode->left);
            q.push(currentnode->right);
        }
    }
}

void display(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeLinkNode* cur = q.front();
        if (cur->next != NULL) {
            cout<<cur->val<<":"<<cur->next->val<<endl;
        }
        else {
            cout<<cur->val<<":"<<"NULL"<<endl;
        }
        q.pop();
        if (cur->left != NULL && cur->right != NULL) {
            q.push(cur->left);
            q.push(cur->right);
        }
    }
}


int main(int argc, const char * argv[]) {
    TreeLinkNode* node1 = new TreeLinkNode(1);
    TreeLinkNode* node2 = new TreeLinkNode(2);
    TreeLinkNode* node3 = new TreeLinkNode(3);
    TreeLinkNode* node4 = new TreeLinkNode(4);
    TreeLinkNode* node5 = new TreeLinkNode(5);
    TreeLinkNode* node6 = new TreeLinkNode(6);
    TreeLinkNode* node7 = new TreeLinkNode(7);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    connect(node1);
    display(node1);
    
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;

    return 0;
}
