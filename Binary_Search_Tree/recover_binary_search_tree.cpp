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
    private:
        TreeNode* first;
        TreeNode* prev;
        TreeNode* middle;
        TreeNode* last;
        
        void inorder(TreeNode* root)
        {
            if(root==NULL)
                return;
            
            // recursive call for leftsubtree
            inorder(root->left);
            
            // for root node
            if(prev!=NULL and root->val<prev->val)
            {
                if(first==NULL)
                {
                    first=prev;
                    middle=root;
                }
                else
                    last=root;
}
            
            prev=root;
            
            // recursive call for rightsubtree
            inorder(root->right);
}
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        
        if(first!=NULL and last!=NULL)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
};

/*
https://leetcode.com/problems/recover-binary-search-tree/
*/