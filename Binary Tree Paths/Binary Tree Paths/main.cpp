//
//  main.cpp
//  Binary Tree Paths
//
//  Created by apple on 16/1/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

vector<string> result;

void Traversal(TreeNode* root, string str) {
    if (root == NULL) return;
    
    stringstream ss;
    if (!(root->left || root->right)) {
        ss << str << root->val;
        ss >> str;
        result.push_back(str);
    }
    else {
        ss << str << root->val << "->";
        ss >> str;
    }
    
    Traversal(root->left, str);
    Traversal(root->right, str);
}

vector<string> binaryTreePaths(TreeNode* root) {
    string s = "";
    Traversal(root, s);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    
    node1->left = node2;
    node1->right = node3;
    node2->right = node5;
    node2->left = node6;
    node3->right = node4;
    
    vector<string> result = binaryTreePaths(node1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    
    return 0;
}
