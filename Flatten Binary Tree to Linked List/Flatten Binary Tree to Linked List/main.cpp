//
//  main.cpp
//  Flatten Binary Tree to Linked List
//
//  Created by apple on 16/6/14.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *rover = new TreeNode(0);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            
            if (cur) {
                rover->right = cur;
                rover->left = NULL;
                rover = cur;

                s.push(cur->right);
                s.push(cur->left);
            }
            
        }
        rover->right = NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
