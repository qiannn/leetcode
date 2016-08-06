//
//  main.cpp
//  Count Complete Tree Nodes
//
//  Created by apple on 16/8/6.
//  Copyright © 2016年 apple. All rights reserved.
//


/*
 用暴力法, recursive求会超时 O(N).
 如果从某节点一直向左的高度 = 一直向右的高度,
 那么以该节点为root的子树一定是complete binary tree.
 而 complete binary tree的节点数,可以用公式算出 2^h - 1.
 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.
 复杂度为O(h^2)
 */

#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        int left = getLeftHeight(root);
        int right = getRightHeight(root);
        
        if (left == right) {
            return (2 << (left - 1)) - 1;
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
        
        return 0;
    }
    
private:
    int getLeftHeight(TreeNode* root) {
        int count = 0;
        while (root) {
            count++;
            root = root->left;
        }
        return count;
    }
    
    int getRightHeight(TreeNode* root) {
        int count = 0;
        while (root) {
            count++;
            root = root->right;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
