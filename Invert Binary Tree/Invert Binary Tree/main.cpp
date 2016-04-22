//
//  main.cpp
//  Invert Binary Tree
//
//  Created by apple on 15/11/14.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    stack<TreeNode*> path;
    path.push(root);
    while (!path.empty()) {
        TreeNode* cur = path.top();
        path.pop();
        
        TreeNode* temp;
        temp = cur->right;
        cur->right = cur->left;
        cur->left = temp;
        
        if (cur->left != NULL) {
            path.push(cur->left);
        }
        
        if (cur->right != NULL) {
            path.push(cur->right);
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(9);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    TreeNode* newtree = invertTree(node1);
    
    
    return 0;
}
