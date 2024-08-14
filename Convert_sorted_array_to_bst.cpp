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
    TreeNode* buildTree(vector<int>&nums,int left,int right){

       if(left>right)
       return 0;
        int mid=(left+right)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=buildTree(nums,left,mid-1);
        temp->right=buildTree(nums,mid+1,right);
        return temp;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
};