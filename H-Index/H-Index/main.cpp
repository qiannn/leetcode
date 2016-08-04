//
//  main.cpp
//  H-Index
//
//  Created by apple on 15/11/11.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int>& citations) {
    int hindex = 0;
    int N = citations.size();
    sort(citations.begin(), citations.end());
    
    for (int h = 0; h < N; h++) {
        if (citations[N - 1 - h] >= h + 1) {
            if (citations[N - 1 - h - 1] <= h + 1) {
                hindex = h + 1 > hindex ? h + 1 : hindex;
            }
        }
    }
    
    return hindex;
}

int main(int argc, const char * argv[]) {
    vector<int> citations = {3, 0, 6, 1, 5};
    
    cout <<hIndex(citations)<<endl;
    
    return 0;
}
