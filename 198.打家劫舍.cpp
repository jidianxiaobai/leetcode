/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int i = 2;
        for (; i < nums.size(); i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
