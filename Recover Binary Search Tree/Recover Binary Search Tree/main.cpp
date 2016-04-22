//
//  main.cpp
//  Recover Binary Search Tree
//
//  Created by apple on 15/12/14.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

TreeNode *p, *q, *prevnode;

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    if (prevnode != NULL) {
        if (prevnode->val > root->val) {
            if (p == NULL) {
                p = prevnode;
            }
            q = root;
        }
    }
    prevnode = root;
    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    p = NULL;
    q = NULL;
    prevnode = NULL;
    
    inorder(root);
    if (p && q) {
        int tmp = 0;
        tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode* node1(new TreeNode(1));
    TreeNode* node2(new TreeNode(2));
    TreeNode* node3(new TreeNode(3));
    TreeNode* node4(new TreeNode(4));
    TreeNode* node5(new TreeNode(5));
    TreeNode* node6(new TreeNode(6));
    TreeNode* node7(new TreeNode(7));
    TreeNode* node8(new TreeNode(8));
    TreeNode* node9(new TreeNode(9));
 /*
    node5->left = node3;
    node5->right = node8;
    
    node3->left = node2;
    node3->right = node4;
    
    node2->left = node9;
    
    node8->left = node6;
    node8->right = node1;
    
    node6->right = node7;
 */
    node1->left = node2;
    node1->right = node3;
    recoverTree(node1);
    cout << "what" << endl;
    return 0;
}
