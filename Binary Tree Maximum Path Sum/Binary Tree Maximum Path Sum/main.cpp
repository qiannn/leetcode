//
//  main.cpp
//  Binary Tree Maximum Path Sum
//
//  Created by apple on 15/10/28.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

int Max = INT_MIN;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

int max(int x, int y) {
    return x > y ? x : y;
}

int maxPath(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int rootsum = root->val;
    int answer;
    int left = maxPath(root->left);
    int right = maxPath(root->right);
    
    if (root->left != NULL) {
        if (left >= 0) {
            rootsum += left;
        }
        else if(left > rootsum) {
            rootsum = left;
        }
    }
    
    if (root->right != NULL) {
        if (right >= 0) {
            rootsum += right;
        }
        else if(right > rootsum) {
            rootsum = right;
        }
    }
    
    if (rootsum > Max) {
        Max = rootsum;
    }
    
    answer = max(left, right) + root->val;
    
    return max(answer, root->val);
}

int maxPathSum(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    maxPath(root);
    
    return Max;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node1 = new TreeNode(-2);
//    TreeNode* node2 = new TreeNode(-1);
//    TreeNode* node3 = new TreeNode(3);
//    node1->left = node2;
//    node1->right = node3;
    std::cout<<maxPathSum(node1)<<std::endl;
    return 0;
}
