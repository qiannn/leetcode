//
//  main.cpp
//  Max Points on a Line
//
//  Created by apple on 16/4/13.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Line {
public:
    Point p1;
    Point p2;
    Line() : p1(0, 0), p2(0, 0) {};
    Line(Point& x, Point& y) : p1(x), p2(y) {};
};

class HashFunc {
public:
    
    size_t operator()(const Line& l) const{
        if (l.p2.x - l.p1.x == 0)
            return (size_t)(INT_MAX - 1);
        return (size_t)((l.p2.y - l.p1.y) / (l.p2.x - l.p1.x));
    }
};

class EqualFunc {
public:
    bool operator()(const Line& l1, const Line& l2) const {
        bool sameline1, sameline2;
        sameline1 = (l1.p1.y - l2.p1.y) * (l1.p1.x - l2.p2.x) == (l1.p1.y - l2.p2.y) * (l1.p1.x - l2.p1.x);
        sameline2 = (l1.p2.y - l2.p1.y) * (l1.p2.x - l2.p2.x) == (l1.p2.y - l2.p2.y) * (l1.p2.x - l2.p1.x);
        return sameline1 && sameline2;
    }
    
};

class Solution {
public:
    bool samePoint(Point &a, Point &b) {
        if (a.x == b.x && a.y == b.y)
            return true;
        return false;
    }
    
    int maxPoints(vector<Point>& points) {
        if (points.empty())
            return 0;
        int max = 1;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<Line, int, HashFunc, EqualFunc> hashtable;
            int duplicate = 0;
            for (int j = i + 1; j < points.size(); j++) {
                Line newline(points[i], points[j]);
                if (samePoint(points[i], points[j])) {
                    duplicate++;
                    continue;
                }
 
                if (hashtable.count(newline) == 0) {
                    hashtable[newline] = 2;
                }
                else {
                    hashtable[newline]++;
                }
            }
            auto iter = hashtable.begin();
            //case:[[0,0],[0,0]]
            if (iter == hashtable.end()) {
                if (1 + duplicate > max)
                    max = duplicate + 1;
            }
            for (; iter != hashtable.end(); iter++) {
                cout << iter->first.p1.x <<" "<< iter->first.p1.y<< endl;
                iter->second += duplicate;
                if (iter->second > max)
                    max = iter->second;
            }
        }
        return max;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /*
    vector<Point> points = {Point(1,1), Point(2,2), Point(3,3),
                            Point(3,2), Point(4,1), Point(5,1),
                            Point(3,1), Point(4,2), Point(1,0),
                            Point(5,2), Point(7,3), Point(9,4)};
    */
    vector<Point> points = {Point(0,0), Point(0,0), Point(0,0)};
    Solution s;
    cout << s.maxPoints(points) << endl;
    return 0;
}
