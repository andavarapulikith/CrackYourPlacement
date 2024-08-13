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
    bool check_match(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)
        return true;
        if(root1==NULL)
        return false;
        if(root2==NULL)
        return false;
        if(root1->val!=root2->val)
        return false;
        return check_match(root1->left,root2->left) && check_match(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)
        return true;
        if(root==NULL)
        return false;
        if(subRoot==NULL)
        return true;
        bool ans=false;
        if(root->val== subRoot->val)
        ans=ans|| check_match(root,subRoot);
        if(ans)
        return ans;
        else
        {
         ans=ans||isSubtree(root->left,subRoot); 
         ans=ans||isSubtree(root->right,subRoot);
        }
         return ans;

        
    }
};