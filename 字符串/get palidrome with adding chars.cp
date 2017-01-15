#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 题目描述：
    给定一个字符串 str, 可以在 str 的任意位置添加字符,请返回在添加字符最少的情况下, 让 str 整体都是一个回文串
*/


class Solution {
public:
    
    vector<vector<int>> getDp(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = 1; i < s.size(); i++) {
            dp[i - 1][i] = s[i - 1] == s[i] ? 0 : 1;
            for (int j = i - 2; j > -1; j--) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i - 1][j + 1];
                } else {
                    dp[i][j] = min(dp[i -1][j], dp[i][j + 1]) + 1;
                }
            }
        }
        return dp;
    }
};
