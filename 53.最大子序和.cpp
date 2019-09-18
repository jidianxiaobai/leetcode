/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //特殊情况的处理
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        //一般情况 size>=2
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int maxValue = dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            maxValue = max(maxValue,dp[i]);
        }
        return maxValue;
    }
};

