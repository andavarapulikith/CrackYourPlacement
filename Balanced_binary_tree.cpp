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
    int check_balance(TreeNode* root,int level,int &ans){
        if(root==0)
        return 1;
        int lv=check_balance(root->left,level+1,ans);
        int rv=check_balance(root->right,level+1,ans);
        if(abs(lv-rv)>=2)
        ans=ans && 0;
        return 1+max(lv,rv);
    }
    bool isBalanced(TreeNode* root) {
        if(root==0)
        return true;
        int ans=1;
        check_balance(root,0,ans);
        return ans;
        
    }
};