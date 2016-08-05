//
//  main.cpp
//  Binary Search Tree Iterator
//
//  Created by apple on 16/8/5.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        helper(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        if (!hasNext()) {
            return -1;
        }
        
        TreeNode* topNode = s.top();
        int value = topNode->val;
        
        s.pop();
        if (topNode->right)
            helper(topNode->right);
            
        return value;
    }
    
private:
    void helper(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TreeNode* root = new TreeNode(5);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next();
    return 0;
}
