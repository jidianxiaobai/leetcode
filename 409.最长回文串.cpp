/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        int ret = 0;
        vector<int> map(128,0);
        for(int i=0; i<len; i++){
            map[s[i]]++;
        }
        for(int i=0; i<128; i++){
            if(map[i]%2 == 1 && ret%2 == 0) ret++;
            ret = (map[i]%2==0) ? ret + map[i] : ret + map[i] - 1;
        }
        return ret;
    }
};

