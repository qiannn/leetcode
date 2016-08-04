//
//  main.cpp
//  Construct Binary Tree from Inorder and Postorder Traversal
//
//  Created by apple on 15/12/1.
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

TreeNode* build(vector<int>::iterator instart,
                vector<int>::iterator inend,
                vector<int>::iterator poststart,
                vector<int>::iterator postend) {
    if (instart == inend || poststart == postend) {
        return NULL;
    }
    
    int rootval = *(postend - 1);
    TreeNode* root = new TreeNode(rootval);
    
    vector<int>::iterator iter = find(instart, inend, rootval);
    
    int size = iter - instart;
    
    root->left = build(instart , iter,
                       poststart, poststart + size);
    root->right = build(iter + 1, inend,
                        poststart + size, postend - 1);
    
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
    return build(inorder.begin(), inorder.end(),
                 postorder.begin(), postorder.end());
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
    vector<int> preorder = {1,3,5,7,8,4};
    vector<int> inorder = {5,3,1,8,7,4};
    vector<int> postorder = {5,3,8,4,7,1};
    levelTraversal(buildTree(inorder, postorder));
    return 0;
}
