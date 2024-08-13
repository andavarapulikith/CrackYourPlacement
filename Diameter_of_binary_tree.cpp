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
    int finddiameter(TreeNode *root ,int &diameter){
        if(!root)
        return 0;
        int lefti=finddiameter(root->left,diameter);
        int righti=finddiameter(root->right,diameter);
        diameter=max(diameter,lefti+righti);
       return  1+max(lefti,righti);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        finddiameter(root,diameter);
        return diameter;
        
    }
};