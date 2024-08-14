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
    void find_paths(TreeNode* root,string str,vector<string>&ans){
        if(root==0)
        return;
        if(root->left==0 && root->right==0)
        {
            if(str.length()>=0){
              
            ans.push_back(str+to_string(root->val));
            }
            return;
        }
        
        find_paths(root->left,str+to_string(root->val)+"->",ans);
        find_paths(root->right,str+to_string(root->val)+"->",ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str="";
        find_paths(root,str,ans);
        return ans;
    }
};