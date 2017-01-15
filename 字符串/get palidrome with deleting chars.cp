#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 题目描述：
    给定一个字符串 str, 可以在 str 的任意位置删除字符,请返回在删除字符最少的情况下, 让 str 整体都是一个回文串
*/


class Solution {
public:
    
    bool isPalidomore(string& s) {
        if (s.size() <= 1) {
            return 0;
        }
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            if (s[begin++] != s[end--]) {
                return false;
            }
        }
        
        return true;
    }
    
    int solve(string& s) {
        if (isPalidomore(s)) {
            return 0;
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        string t = s;
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return s.size() - dp[s.size()][s.size()];
    }
};
