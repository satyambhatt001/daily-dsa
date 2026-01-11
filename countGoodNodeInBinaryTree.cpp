class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, int maxSoFar) {
        if (root == NULL)
            return;

        // Check if current node is good
        if (root->val >= maxSoFar) {
            count++;
            maxSoFar = root->val;
        }

        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};
