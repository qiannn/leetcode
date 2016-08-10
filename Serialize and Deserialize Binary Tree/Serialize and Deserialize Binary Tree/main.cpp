//
//  main.cpp
//  Serialize and Deserialize Binary Tree
//
//  Created by apple on 16/8/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree;
        BuildString(root, tree);
        return tree;
    }
    
    void BuildString(TreeNode* root, string& tree) {
        if (!root) {
            tree.append("null").append(",");
        }
        else {
            tree.append(to_string(root->val)).append(",");
            BuildString(root->left, tree);
            BuildString(root->right, tree);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            q.push(node);
        }
        return BuildTree(q);
    }
    
    TreeNode* BuildTree(queue<string> q) {
        if (q.empty())
            return NULL;
        if (q.front() == "null") {
            q.pop();
            return NULL;
        }
        
        TreeNode* node = new TreeNode(stoi(q.front()));
        q.pop();
        node->left = BuildTree(q);
        node->right = BuildTree(q);
        
        return node;
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

    Codec code;
    string data  =code.serialize(root);
    cout << data << endl;
    
    queue<TreeNode*> q;
    stringstream ss;
    q.push(code.deserialize(code.serialize(root)));
    
    while (!q.empty()) {
        TreeNode* front = q.front();
        if (front)
            cout << front->val << " ";
        q.pop();
    }
    
    return 0;
}
