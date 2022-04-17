/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
}
    TreeNode* buildTree(TreeNode* node,vector<int> ans,int count)
    {
        if(count==ans.size())
            return node;
        node=new TreeNode(ans[count]);
        node->left=NULL;
        node->right=buildTree(node->right,ans,count+1);
        return node;
}
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        TreeNode* node;
        node=buildTree(node,ans,0);
        return node;
    }
};

/*
https://leetcode.com/problems/increasing-order-search-tree/
*/