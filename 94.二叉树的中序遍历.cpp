/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <iostream>
using namespace std;
/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution
{
public:
    void InOrder(TreeNode *root,vector<int>& ret)
    {
        if (root != NULL)
        {
            InOrder(root->left,ret);
            ret.push_back(root->val);
            InOrder(root->right,ret);
        }
    }
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> ret;
        InOrder(root,ret);
        return ret;
    }
};
