/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include<vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0){
            return 0;
        }
        int m = matrix[0].size();
        vector<int> heigth(m,0),left(m,-1),right(m,m);
        int i, j, lastOcc, maxArea = 0;
        for(i = 0;i < n; i++){
            //update height
            for(j = 0;j < m; j++){
                if(matrix[i][j] == '1'){
                    heigth[j] += 1 ;
                }else{
                    heigth[j] = 0;
                }
            }
            //update left
            lastOcc = -1;
            for(j = 0;j < m; j++){
                if(matrix[i][j] == '1'){
                    left[j] = max(lastOcc,left[j]);
                }else{
                    lastOcc = j;
                    left[j] = -1;
                }
            }
            //update right
            lastOcc = m;
            for(j = m-1;j >= 0; j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j],lastOcc);
                }else{
                    lastOcc = j;
                    right[j] = m;
                }
            }
            //update area
            for(j = 0;j < m ;j++){
                maxArea = max(maxArea,(right[j]-left[j] - 1)*heigth[j]);
            }
        }
        return maxArea;
    }
};

