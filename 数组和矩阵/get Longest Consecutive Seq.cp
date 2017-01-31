#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

/*
 题目描述：
    给定一个数组，返回其中最长的连续序列的长度
 
 */

/*----------------------------------------------------------------------------------*/

class Solution {
public:
    int getLongestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        int res = 1;
        unordered_map<int, int> map;
        for(auto num : nums) {
            if (map.find(num) == map.end()) {
                map[num] = 1;
                if (map.find(num - 1) != map.end()) {
                    res = max(res, merge(map, num - 1, num));
                }
                
                if (map.find(num + 1) != map.end()) {
                    res = max(res, merge(map, num, num + 1));
                }
            }
        }
        
        return res;
    }
    
    int merge(unordered_map<int, int>& map, int less, int more) {
        int left = less - map[less] + 1;
        int right = more + map[more] - 1;
        
        int length = right - left + 1;
        map[less] = length;
        map[more] = length;
        
        return length;
    }
    

};


