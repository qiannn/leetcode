//
//  main.cpp
//  Count Primes
//
//  Created by apple on 15/12/22.
//  Copyright © 2015年 apple. All rights reserved.
//

#include <iostream>

int countPrimes(int n) {
    bool isPrime[n];
    memset(isPrime, 1, n * sizeof(bool));
    
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << countPrimes(10) << std::endl;
    return 0;
}
