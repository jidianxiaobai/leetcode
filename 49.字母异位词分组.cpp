/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include<string>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hashmap;
        for(auto s : strs){
            string key = s;
            sort(key.begin(),key.end()); //对其进行排序
            hashmap[key].push_back(s);
        }
        vector<vector<string>> ret;
        int cnt = 0;
        for(auto i : hashmap){
            ret.push_back(i.second);
        }
        return ret;
    }
};

