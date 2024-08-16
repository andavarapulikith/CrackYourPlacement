class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        long long maxi = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            long long end = 0;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long currIdx = q.front().second - start;
                q.pop();
                
                if (i == size - 1) {
                    end = currIdx;
                }
                
                if (node->left) {
                    q.push({node->left, 2 * currIdx});
                }
                if (node->right) {
                    q.push({node->right, 2 * currIdx + 1});
                }
            }
            
            maxi = max(maxi, end + 1);
        }
        
        return maxi;
    }
};
