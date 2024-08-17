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
    int cameras=0;
    int min_cameras(TreeNode* root){
        if(root==0)
        return 1;
        int lh=min_cameras(root->left);
        int rh=min_cameras(root->right);
        if(lh==-1 || rh==-1)
        {
            cameras++;
            return 0;
        }
        if(lh==0 || rh==0)
        {
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(min_cameras(root)==-1)
        cameras++;
        return cameras;
    }
};