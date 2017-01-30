#include <iostream>
#include <vector>

using namespace std;

/*
 题目描述：
 给定数组 arr，arr 中所有的值都是正整数且不重复，每个值都代表一个面值，每种面值的货币可以使用任意张，再给定一个整数 aim 代表要找的钱数，求组成 aim 最少货币数
 
 */



/*----------------------------------------------------------------------------------*/


class Solution {
public:
    int getCoinNum(vector<int>& arr, int aim) {
        if (arr.empty() || aim == 0) {
            return 0;
        }
        
        int res = INT_MAX;
        vector<int> dp(aim + 1, res);
        
        for(int money = 0; money <= aim; money++) {
            if (money - arr[0] > 0 && dp[money - arr[0]] != res) {
                dp[money] = dp[money - arr[0]] + 1;
            }
        }
        
        for(int i = 1; i < arr.size(); i++) {
            for (int money = 1; money <= aim; money++) {
                int left = INT_MAX;
                if (money - arr[i] >= 0 && dp[money - arr[i]] != INT_MAX) {
                    left = dp[money - arr[i]] + 1;
                }
                dp[money] = min(dp[money], left);
            }
        }
        
        return dp[aim] == INT_MAX ? -1 : dp[aim];
        
    }
    
};

