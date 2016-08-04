//
//  main.cpp
//  Path Sum
//
//  Created by apple on 15/12/3.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {};
};

bool found = false;

void Traversal(TreeNode* root, int sum) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        if (sum - root->val == 0) {
            found = true;
        }
    }
    
    Traversal(root->left, sum - root->val);
    Traversal(root->right, sum - root->val);
}

bool hasPathSum(TreeNode* root, int sum) {
    Traversal(root, sum);
    return found;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(13);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(2);
    TreeNode* node9 = new TreeNode(5);
    TreeNode* node10 = new TreeNode(1);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    //    node2->right = node5;
    
    node3->left = node5;
    node3->right = node6;
    
    node4->left = node7;
    node4->right = node8;
    
    node6->left = node9;
    node6->right = node10;
    
    if (hasPathSum(node1, 26)) {
        cout << "yes" << endl;
    }
    else {
        cout << "ops" << endl;
    }
    return 0;
}
