//
//  main.cpp
//  Kth Smallest Element in a BST
//
//  Created by apple on 16/8/7.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        
        MidOrder(root, v);
        return v[k - 1];
    }
    
    void MidOrder(TreeNode* root, vector<int>& v) {
        if (!root)
            return ;
        
        MidOrder(root->left, v);
        
        v.push_back(root->val);
        
        MidOrder(root->right, v);
    }
     */
    
    int kthSmallest(TreeNode* root, int k) {
        int leftCnt = Count(root->left);
        
        if (leftCnt + 1 == k) {
            return root->val;
        }
        else if (leftCnt + 1 > k){
            return kthSmallest(root->left, k);
        }
        else {
            return kthSmallest(root->right, k - (leftCnt + 1));
        }
    }
    
    int Count(TreeNode* root) {
        if (!root)
            return 0;
        
        return Count(root->right) + Count(root->left) + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
