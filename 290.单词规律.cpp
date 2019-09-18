/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */
#include<map>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string,char> Map;
        vector<bool> used(128,0); //记录pattern中的字符是否出现过
        str.push_back(' '); //方便分割
        int i=0, j=0;
        string strtemp;
        map<string,char>::iterator iter;
        for(; i<pattern.length() && j<str.length(); i++,j++){
            while(str[j]!=' ') strtemp.push_back(str[j++]);
            iter = Map.find(strtemp);
            if(iter == Map.end()){
                if(used[pattern[i]] == true) return false;
                Map.insert(pair<string,char>(strtemp,pattern[i]));
                used[pattern[i]] = true;
            }else{
                if(iter->second != pattern[i]) return false;
            }
            strtemp = "";
        }
        return i==pattern.length() && j==str.length();
    }
};

