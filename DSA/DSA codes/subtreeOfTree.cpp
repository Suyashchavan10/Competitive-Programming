#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};
class Solution {
public:
    void inorder(TreeNode* node, vector<int> &tree)
    {
        if(node == nullptr)
            return;
        inorder(node->left, tree);
        tree.push_back(node->val);
        inorder(node->right, tree);
    }
    void preorder(TreeNode* node, vector<int> &tree)
    {
        if(node == nullptr)
            return;
        tree.push_back(node->val);
        preorder(node->left, tree);
        preorder(node->right, tree);
    }
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        vector<int> pre1, pre2, in1, in2;
        inorder(root, in1);
        inorder(subRoot, in2);
        preorder(root, pre1);
        preorder(subRoot, pre2);
        bool ans1 = true, ans2 = true;
        for(int i=0;i<in2.size();i++)
        {
            if(in1[i] != in2[i])
            {
                ans1 = false;
                break;
            }
        }
        for(int i=0;i<pre2.size();i++)
        {
            if(pre1[i] != pre2[i])
            {
                ans2 = false;
                break;
            }
        }
        return ans1&&ans2;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)
            return true;
        else if(subRoot == nullptr)
            return true;
        else if(root == nullptr)
            return false;
        bool finans;
        if(root->val == subRoot->val)
        {
            finans = check(root, subRoot);
        }
        if(!finans)
        {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return finans;
    }
};