/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void find_parent(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
    if(root==0)
    return;
    if(root->left)
    parent[root->left]=root;
    if(root->right)
    parent[root->right]=root;
    find_parent(root->left,parent);
    find_parent(root->right,parent);
   }
  
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        find_parent(root,parent);
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        map<TreeNode*,bool>visited;
        q.push({target,0});
        visited[target]=true;
        while(!q.empty()){
            int l=q.front().second;
            TreeNode* node=q.front().first;
            q.pop();
            if(l==k)
            {
            ans.push_back(node->val);
            }
            else{
            if(node->left && visited.find(node->left)==visited.end()){
            q.push({node->left,l+1});
            visited[node->left]=true;
            }
            if(node->right && visited.find(node->right)==visited.end()){
            q.push({node->right,l+1});
            visited[node->right]=true;
            }
            if(parent.find(node)!=parent.end() && visited.find(parent[node])==visited.end()){
                q.push({parent[node],l+1});
                visited[parent[node]]=true;
            }
            }

        }
        return ans;

    }
};