/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> t(n+1,0);
        t[0] = t[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                t[i] += t[j-1]*t[i-j];
            }
        }
        return t[n];
    }
};

