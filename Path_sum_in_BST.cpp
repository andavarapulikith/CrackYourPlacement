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
    bool check_sum(TreeNode *root,int sum,int targetsum){
         if(root==0)
        return false;
        if(root->left==0 && root->right==0)
        {
            if(sum+root->val==targetsum)
            return true;
            return false;
        }
       
        return check_sum(root->left,sum+root->val,targetsum) || check_sum(root->right,sum+root->val,targetsum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==0)
        return false;
        return check_sum(root,0,targetSum);
        
    }
};