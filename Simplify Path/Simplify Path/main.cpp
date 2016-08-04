//
//  main.cpp
//  Simplify Path
//
//  Created by apple on 15/11/23.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string simplipyPath(string path) {
    string ans = "";
    vector<string> filepath;
    stringstream ss(path);
    string s;
    while (getline(ss, s, '/')) {
        filepath.push_back(s);
    }
    
    int count = 0;
    for (int i = filepath.size() - 1; i >= 0; --i) {
        if (filepath[i] != ".") {
            if (filepath[i] == "..") {
                count ++;
            }
            else if (filepath[i] != ""){
                if (count > 0) {
                    count --;
                }
                else {
                    ans = "/" + filepath[i] + ans;
                }
            }
        }
    }
    
    if (ans == "") {
        ans = "/";
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {

    cout << simplipyPath("/a/./b/../../c/") << endl;
    return 0;
}
