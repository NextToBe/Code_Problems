#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 题目描述：
    给定两个字符串str1 和 str2，再给定三个整数inc, del, rep 分别代表插入，删除，替换一个字符的代价，返回将 str1 变成 str2 的最小代价
*/

/*----------------------------------------------------------------------------------*/

class Solution {
public:
    int getMinCost(string str1, string str2, int inc, int del, int rep) {
        // dp[i][j] 代表 str1[0...i - 1] 编辑成 str2[0...j - 1] 的最小代价
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        
        for (int i = 1; i < str1.size(); i++) {
            dp[i][0] = del * i;
        }
        
        for (int j = 1; j < str2.size(); j++) {
            dp[0][j] = inc * j;
        }
        
        for (int i = 1; i < str1.size(); i++) {
            for (int j = 1; j < str2.size(); j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + rep;
                }
                
                dp[i][j] = min(min(dp[i][j], dp[i - 1][j] + del), dp[i][j - 1] + inc);
            }
        }
        
        return dp[str1.size() - 1][str2.size() - 1];
    }
};

