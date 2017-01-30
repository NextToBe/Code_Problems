#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 题目描述：
    给定一个数组 nums，求数组的最长递增子序列
 */

/*----------------------------------------------------------------------------------*/

class Solution {
public:
    vector<int> getSeq(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return generateSeq(nums, dp);
        
    }
    
    vector<int> generateSeq(vector<int>& nums, vector<int>& dp) {
        int length = 0;
        int index = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > length) {
                length = dp[i];
                index = i;
            }
        }
        
        vector<int> res(length, 0);
        if (length == 0 || index == 0) {
            return res;
        }
        
        res[--length] = nums[index];
        for (int i = index; i >= 0; i--) {
            if (nums[i] < nums[index] && dp[i] == dp[index] - 1) {
                res[--length] = nums[i];
                index = i;
            }
        }
        
        return res;
    }
};

