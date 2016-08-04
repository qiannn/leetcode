//
//  main.cpp
//  Longest Palindromic Substring
//
//  Created by apple on 16/1/2.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    int length = s.size();
    bool dp[length][length];
    int start = 0, end = 0;
    int max = 1;
    memset(dp, false, sizeof(dp));
    for (int len = 1; len <= s.size(); len++) {
        for (int i = 0; i < s.size() - len + 1; i++) {
            int j = i + len - 1;
            if (len == 1) dp[i][j] = true;
            else if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (len > max) {
                    max = len;
                    start = i;
                    end = j;
                }
            }
        }
    }
    string answer;
    answer = s.substr(start, max);
    return answer;
}

/*
int min(int x, int y) {
    return x < y ? x : y;
}

string longestPalindrome(string s) {
    string t = "@";
    for (int i = 0; i < s.size(); i++) {
        t += '#';
        t += s[i];
    }
    t += '#';
    int mid = 0, mx = 0;
    int *p = new int[t.size()];
    memset(p, 0, sizeof(p));
    for (int i = 1; i < t.size(); i++) {
        int j = mid * 2 - 1;
        p[i] = mx > i ? min(mx - i, p[j]) : 1;
        while (t[i + p[i]] == t[i - p[i]]) p[i]++;
        if (i + p[i] > mx) {
            mid = i;
            mx = i + p[i];
        }
    }
    int maxlen = 0, index = 0;
    for (int i = 1; i < t.size(); i++) {
        if (maxlen < p[i]) {
            maxlen = p[i];
            index = i;
        }
    }
    return s.substr((index - maxlen + 1)/2, maxlen - 1);
}
*/
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string test = "cyyoacmjwjubfkzrrbvquqkwhsxvmytmjvbborrtoiyotobzjmohpadfrvmxuagbdczsjuekjrmcwyaovpiogspbslcppxojgbfxhtsxmecgqjfuvahzpgprscjwwutwoiksegfreortttdotgxbfkisyakejihfjnrdngkwjxeituomuhmeiesctywhryqtjimwjadhhymydlsmcpycfdzrjhstxddvoqprrjufvihjcsoseltpyuaywgiocfodtylluuikkqkbrdxgjhrqiselmwnpdzdmpsvbfimnoulayqgdiavdgeiilayrafxlgxxtoqskmtixhbyjikfmsmxwribfzeffccczwdwukubopsoxliagenzwkbiveiajfirzvngverrbcwqmryvckvhpiioccmaqoxgmbwenyeyhzhliusupmrgmrcvwmdnniipvztmtklihobbekkgeopgwipihadswbqhzyxqsdgekazdtnamwzbitwfwezhhqznipalmomanbyezapgpxtjhudlcsfqondoiojkqadacnhcgwkhaxmttfebqelkjfigglxjfqegxpcawhpihrxydprdgavxjygfhgpcylpvsfcizkfbqzdnmxdgsjcekvrhesykldgptbeasktkasyuevtxrcrxmiylrlclocldmiwhuizhuaiophykxskufgjbmcmzpogpmyerzovzhqusxzrjcwgsdpcienkizutedcwrmowwolekockvyukyvmeidhjvbkoortjbemevrsquwnjoaikhbkycvvcscyamffbjyvkqkyeavtlkxyrrnsmqohyyqxzgtjdavgwpsgpjhqzttukynonbnnkuqfxgaatpilrrxhcqhfyyextrvqzktcrtrsbimuokxqtsbfkrgoiznhiysfhzspkpvrhtewthpbafmzgchqpgfsuiddjkhnwchpleibavgmuivfiorpteflholmnxdwewj";
    cout << longestPalindrome(test) << endl;
    return 0;
}
