//
//  main.cpp
//  Validate Binary Search Tree
//
//  Created by apple on 16/4/11.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> order;
        InorderTraversal(root, order);
        for (int i = 1; i < order.size(); i++) {
            if (order[i] <= order[i - 1])
                return false;
        }
        return true;
    }
    
    void InorderTraversal(TreeNode* root, vector<int>& order) {
        if (!root)
            return;
        InorderTraversal(root->left, order);
        order.push_back(root->val);
        InorderTraversal(root->right, order);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(20);
    
    TreeNode* node6 = new TreeNode(19);
    TreeNode* node7 = new TreeNode(21);
    
    node1->left = node2;
    node1->right = node3;
    
    node3->left = node4;
    node3->right = node5;
    
    node5->left = node6;
    node5->right = node7;
    
    if (s.isValidBST(node1))
        std::cout << "yes" << std::endl;
    else
        std::cout << "ops" << std::endl;
    return 0;
}
