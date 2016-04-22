//
//  main.cpp
//  Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by apple on 15/11/30.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int>::iterator prestart,
                vector<int>::iterator preend,
                vector<int>::iterator instart,
                vector<int>::iterator inend) {
    if (prestart == preend || instart == inend) {
        return NULL;
    }
    
    int rootval = *prestart;
    TreeNode* root = new TreeNode(rootval);
    
    vector<int>::iterator iter = find(instart, inend, rootval);
    
    int size = iter - instart;
    
    root->left = build(prestart + 1, prestart + size + 1,
                       instart, iter);
    root->right = build(prestart + size + 1, preend,
                        iter + 1, inend);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    return build(preorder.begin(), preorder.end(),
                 inorder.begin(), inorder.end());
}

void traversal(TreeNode* root) {
    if (root != NULL) {
        cout << root->val << endl;
        traversal(root->left);
        traversal(root->right);
    }
}

void levelTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node != NULL) {
            cout << node->val << endl;
            q.push(node->left);
            q.push(node->right);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> preorder = {1,3,5,7,8,4};
    vector<int> inorder = {5,3,1,8,7,4};
//    traversal(buildTree(preorder, inorder));
    levelTraversal(buildTree(preorder, inorder));
    return 0;
}
