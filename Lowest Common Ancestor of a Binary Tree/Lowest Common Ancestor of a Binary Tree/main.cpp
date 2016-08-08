//
//  main.cpp
//  Lowest Common Ancestor of a Binary Tree
//
//  Created by apple on 16/8/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;
        
        list<TreeNode*> pPath, qPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);
        
        TreeNode* commonNode = NULL;
        while (!pPath.empty() && !qPath.empty()) {
            if (pPath.front() != qPath.front())
                return commonNode;
            commonNode = pPath.front();
            
            pPath.pop_front();
            qPath.pop_front();
        }
        
        return commonNode;
    }
    
    bool FindPath(TreeNode* src, TreeNode* des, list<TreeNode*>& path) {
        if (!src)
            return false;
        
        path.push_back(src);
        
        if (src == des) {
            return true;
        }
        
        bool found = false;
        
        found = (FindPath(src->left, des, path) || FindPath(src->right, des, path));
        
        if (!found)
            path.pop_back();
        
        return found;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TreeNode* root = new TreeNode(6);
    TreeNode* node1 = new TreeNode(2);
    
    TreeNode* node2 = new TreeNode(8);
    
    TreeNode* node3 = new TreeNode(0);
    TreeNode* node4 = new TreeNode(4);
    
    TreeNode* node5 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(9);
    
    TreeNode* node7 = new TreeNode(3);
    TreeNode* node8 = new TreeNode(5);
    
    root->left = node1;
    root->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    node4->left = node7;
    node4->right = node8;
    
    Solution s;
    TreeNode* commonnode = s.lowestCommonAncestor(root, node1, node8);
    cout << commonnode->val << endl;
    return 0;
}
