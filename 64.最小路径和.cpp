/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i,j;
        int n = grid.size(),m = grid[0].size();
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if((i-1>=0) && (j-1>=0)){
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                }
                else if(i-1>=0){
                    grid[i][j] += grid[i-1][j];
                }
                else if(j-1>=0){
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        return grid[n-1][m-1];
    }
};

