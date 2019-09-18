/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include<vector>
using namespace std;
class Solution {
public:
    int binary_search(vector<int> &nums,int value){
        int low = 0,high = nums.size()-1 ,mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == value) break;
            ( nums[mid] < value )? (low = mid + 1) : (high = mid - 1);
        }
        return (nums[mid] == value) ? mid : (high + 1);
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(stack.back() < nums[i])
                stack.push_back(nums[i]);
            else{
                int pos = binary_search(stack,nums[i]);
                stack[pos] = nums[i];
            }
        }
        return stack.size();
    }
};

