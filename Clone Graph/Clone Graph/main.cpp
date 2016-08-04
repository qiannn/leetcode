//
//  main.cpp
//  Clone Graph
//
//  Created by apple on 16/2/20.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    map<int, UndirectedGraphNode*> visited;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        visited[newnode->label] = newnode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            int curnode = node->neighbors[i]->label;
            if (visited.find(curnode) != visited.end()) {
                newnode->neighbors.push_back(visited[curnode]);
            }
            else {
                newnode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        return newnode;
    }
};

void showGraph(UndirectedGraphNode *node) {
    if (node->label == -1) {
        return ;
    }
    cout << node->label << ",";
    node->label = -1;
    for (int i = 0; i < node->neighbors.size(); i++) {
        showGraph(node->neighbors[i]);
    }
    cout << "#";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solution;
    UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
    node0->neighbors.push_back(node1);
    node0->neighbors.push_back(node2);
    node1->neighbors.push_back(node0);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node0);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node2);
    UndirectedGraphNode *newGraph = solution.cloneGraph(node0);
    showGraph(newGraph);
    return 0;
}
