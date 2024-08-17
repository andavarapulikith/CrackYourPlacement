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
    int path_sum(TreeNode* root,int &maxi){
        if(root==0)
        return 0;
        int leftsum=max(0,path_sum(root->left,maxi));
        int rightsum=max(0,path_sum(root->right,maxi));
         maxi=max(maxi,rightsum+leftsum+root->val);
        return root->val+max(leftsum,rightsum);

    }
    int maxPathSum(TreeNode* root) {
        int sum=0;
        int ans=INT_MIN;
        path_sum(root,ans);
        return ans;
        
    }
};