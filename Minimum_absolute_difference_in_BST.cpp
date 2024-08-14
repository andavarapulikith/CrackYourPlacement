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
    TreeNode* prev=NULL;
    void inorder(TreeNode* root,int &ans){
        if(root==0)
        return;
        inorder(root->left,ans);
        if(prev!=0)
        ans=min(ans,abs(prev->val-root->val));
        prev=root;
        inorder(root->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        inorder(root,ans);
        return ans;
    }
};