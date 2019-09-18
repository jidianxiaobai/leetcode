/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long int>> dp(n,vector<long int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){  
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else if(i == 0 && j == 0){
                    //起始点
                    dp[i][j] = 1;
                }else if(i == 0){
                    //第一行
                    dp[i][j] = dp[i][j-1];
                }else if(j == 0){
                    //第一列
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};

