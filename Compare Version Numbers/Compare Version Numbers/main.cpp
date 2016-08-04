//
//  main.cpp
//  Compare Version Numbers
//
//  Created by apple on 16/1/11.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int parseVersion(string& version) {
    if (version.empty()) return 0;
    int point = version.find('.');
    int version_number;
    if (point != -1) {
        version_number = stoi(version.substr(0, point));
        version = version.substr(point + 1, version.size() - point - 1);
    }
    else {
        version_number = stoi(version);
        version = "";
    }
    return version_number;
}

int compareVersion(string version1, string version2) {
    if (version1.empty() && version2.empty()) return 0;
    int v1 = parseVersion(version1);
    int v2 = parseVersion(version2);
    int result = 0;
    if (v1 == v2) {
        return compareVersion(version1, version2);
    }
    else if (v1 > v2) {
        return 1;
    }
    else {
        return -1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << compareVersion("10.10", "10.9") << endl;
    return 0;
}
