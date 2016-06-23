//
//  main.cpp
//  Maximum Depth of Binary Tree
//
//  Created by apple on 16/6/23.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>


// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return GetDepth(root, 0);
    }
    
    int GetDepth(TreeNode* root, int depth) {
        if (!root)
            return depth;
        return std::max(GetDepth(root->left, depth + 1),
                        GetDepth(root->right, depth + 1));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
