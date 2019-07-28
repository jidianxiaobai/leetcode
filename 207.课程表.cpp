/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //邻接表 存储入度、后继节点
        vector<vector<int>> adjList(numCourses,{0});
        for(auto v : prerequisites){
            adjList[v[0]][0]++;//入度++
            adjList[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!adjList[i][0]){
                q.push(i);
            }
        }
        int cnt = 0,v,w;
        while(!q.empty()){
            v = q.front();
            q.pop();
            cnt++;
            if(adjList[v].size()>1){//有后继结点
                for(int i = 1;i<adjList[v].size();i++){
                    w = adjList[v][i];
                    adjList[w][0]--;//入度减一
                    if(!adjList[w][0]){
                        q.push(w);
                    }
                }

            }
        }
        if(cnt==numCourses)
            return true;
        return false;
    }
};
