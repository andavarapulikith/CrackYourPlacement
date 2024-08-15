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
    int maxlevel=-1;
   void rightview(TreeNode *root,int level,vector<int>&ans){
    if(root==0)
    return;
    if(maxlevel<level)
    {
    ans.push_back(root->val);
    maxlevel=level;
    }
    rightview(root->right,level+1,ans);
    rightview(root->left,level+1,ans);

   }
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;
       rightview(root,0,ans);
       return ans;
    }
};