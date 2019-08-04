/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
#include <iostream>
#include <vector>
using namespace std;
/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>{};
        return generate(1, n);
    }
    vector<TreeNode *> generate(int left, int right)
    {
        vector<TreeNode *> ret;
        if (left > right)
        {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode *> lchild = generate(left, i - 1);
            vector<TreeNode *> rchild = generate(i + 1, right);
            for (auto l : lchild)
            {
                for (auto r : rchild)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
