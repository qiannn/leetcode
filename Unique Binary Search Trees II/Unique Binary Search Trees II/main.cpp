//
//  main.cpp
//  Unique Binary Search Trees II
//
//  Created by apple on 15/12/17.
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

/*
typedef vector<int> preorder;
typedef vector<preorder > preorder_collection;

preorder createPreorder(int root, preorder& left, preorder& right) {
    preorder neworder;
    
    neworder.push_back(root);
    for (int i = 0; i < left.size(); i++) {
        if (left[i] != 0) {
            neworder.push_back(left[i]);
        }
    }
    
    for (int i = 0; i < right.size(); i++) {
        if (right[i] != 0) {
            neworder.push_back(right[i] + root);
        }
    }

    return neworder;
}

preorder_collection createCollection(int root, preorder_collection& left
                                     , preorder_collection& right) {
    preorder_collection newcollection;
    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            preorder neworder;
            neworder = createPreorder(root, left[i], right[j]);
            newcollection.push_back(neworder);
        }
    }
    return newcollection;
}

TreeNode* build(vector<int>::iterator prestart,
                vector<int>::iterator preend,
                vector<int>::iterator instart,
                vector<int>::iterator inend) {
    if (prestart == preend || instart == inend) {
        return NULL;
    }
    
    int rootval = *prestart;
    TreeNode* root = new TreeNode(rootval);
    
    vector<int>::iterator iter = find(instart, inend, rootval);
    
    int size = iter - instart;
    
    root->left = build(prestart + 1, prestart + size + 1,
                       instart, iter);
    root->right = build(prestart + size + 1, preend,
                        iter + 1, inend);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    return build(preorder.begin(), preorder.end(),
                 inorder.begin(), inorder.end());
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> answer;
    vector<preorder_collection> dp;
    
    if(n == 0) {
        return answer;
    }
    
    preorder tmp;
    tmp.push_back(0);
    preorder_collection initcollection;
    initcollection.push_back(tmp);
    dp.push_back(initcollection);
    
    for (int i = 1; i <= n; i++) {
        preorder_collection newcollection;
        for (int j = 1; j <= i; ++j) {
            preorder_collection jcollection;
            jcollection = createCollection(j, dp[j-1], dp[i-j]);
            newcollection.insert(newcollection.begin(),
                                 jcollection.begin(),jcollection.end());
        }
        dp.push_back(newcollection);
    }
    
    vector<int> inorder;
    for (int i = 1; i <= n; i++) {
        inorder.push_back(i);
    }
    
    for (int i = 0; i < dp[n].size(); i++) {
        answer.push_back(buildTree(dp[n][i], inorder));
    }
    
    return answer;
}
*/

void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    cout << root->val;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> answer;
    if (start > end) {
        answer.push_back(NULL);
        return answer;
    }
    
    for (int i = start; i <= end; i ++) {
        vector<TreeNode*> lefttree = generateTrees(start, i - 1);
        vector<TreeNode*> righttree = generateTrees(i + 1, end);
        for (int x = 0; x < lefttree.size(); x++) {
            for (int y = 0; y < righttree.size(); y++) {
                TreeNode* node = new TreeNode(i);
                node->left = lefttree[x];
                node->right = righttree[y];
                answer.push_back(node);
            }
        }
    }
    return answer;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
        vector<TreeNode*> emptyv;
        return emptyv;
    }
    return generateTrees(1, n);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<TreeNode*> answer;
    
    answer = generateTrees(4);
    for (int i = 0; i < answer.size(); i++) {
        preorderTraversal(answer[i]);
        cout << endl;
    }
    return 0;
}
