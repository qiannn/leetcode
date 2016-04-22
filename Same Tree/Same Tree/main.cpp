//
//  main.cpp
//  Same Tree
//
//  Created by apple on 15/12/5.
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

void preorder(TreeNode* root, vector<int>& order) {
    if (root == NULL) {
        return;
    }

    order.push_back(root->val);
    preorder(root->left, order);
    preorder(root->right, order);
}

void inorder(TreeNode* root, vector<int>& order) {
    if (root == NULL) {
        return;
    }
    
    preorder(root->left, order);
    order.push_back(root->val);
    preorder(root->right, order);
}

bool isSame = true;

void Traversal(TreeNode* p, TreeNode* q) {
    if ((p == NULL) ^ (q == NULL)) {
        isSame = false;
        return;
    }
    else if (p == NULL && q == NULL) {
        return;
    }
    else if (p->val != q->val){
        isSame = false;
    }
    
    Traversal(p->left, q->left);
    Traversal(p->right, q->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
/*
    vector<int> ppreorder;
    vector<int> pinorder;
    vector<int> qpreorder;
    vector<int> qinorder;
    
    preorder(p, ppreorder);
    preorder(q, qpreorder);
    inorder(p, pinorder);
    inorder(q, qinorder);
    
    if (ppreorder == qpreorder && pinorder == qinorder) {
        return true;
    }
 */
    Traversal(p, q);
    return isSame;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(1);
 
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(1);
    
    node1->left = node2;
    node3->right = node4;
    
    if (isSameTree(node1, node3)) {
        cout << "yep" << endl;
    }
    else {
        cout << "ops" << endl;
    }
    return 0;
}
