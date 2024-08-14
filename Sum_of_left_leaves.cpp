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
    
    void leaf_values(TreeNode *root,int flag,int &ans){
        if(root==0)
        return;
        leaf_values(root->left,0,ans);
        if(root->left==0 && root->right==0){
            if( flag==0){
              ans+=root->val;
            }

        }
        leaf_values(root->right,1,ans);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        map<int,int>mpp;
        int ans=0;
        leaf_values(root,1,ans);
        
        
        return ans;

        
    }
};