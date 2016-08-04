//
//  main.cpp
//  Number of Islands
//
//  Created by apple on 15/11/2.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class point {
public:
    point(int X, int Y) : x(X), y(Y) {};
    
    bool operator < (const point& p) const{
        return y < p.y || (y == p.y && x < p.x);
    }
    
    int x;
    int y;
};

void dfs(vector<vector<char>>& grid, point start) {
    int x = start.x;
    int y = start.y;
    
    if (grid[y][x] == '1') {
        grid[y][x] = 'x';
    }
    
    if (x + 1 < grid[0].size() && grid[y][x + 1] == '1') {
        point p(x + 1, y);
        dfs(grid, p);
    }
    
    if (y + 1 < grid.size() && grid[y + 1][x] == '1') {
        point p(x, y + 1);
        dfs(grid, p);
    }
    
    if (x - 1 > -1 && grid[y][x - 1] == '1') {
        point p(x - 1, y);
        dfs(grid, p);
    }
    
    if (y - 1 > -1 && grid[y - 1][x] == '1') {
        point p(x, y - 1);
        dfs(grid, p);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int x = 0;
    int y = 0;
    int num = 0;
    while (y < grid.size()) {
        x = 0;
        while (x < grid[y].size()) {
            if (grid[y][x] == '1') {
                point p(x, y);
                dfs(grid, p);
                num++;
            }
            x++;
        }
        y++;
    }
    return num;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid;
    vector<char> s1 = {'1','1','0','0','0'};
    vector<char> s2 = {'1','1','0','0','0'};
    vector<char> s3 = {'0','0','1','0','0'};
    vector<char> s4 = {'0','0','0','1','1'};
    
    grid.push_back(s1);
    grid.push_back(s2);
    grid.push_back(s3);
    grid.push_back(s4);
    
    cout << numIslands(grid)<<endl;
    return 0;
}
