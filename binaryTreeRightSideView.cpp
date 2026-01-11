class Solution {
public:
    // This vector will store the final right side view
    // res[i] will store the value of the rightmost node at level i
    vector<int> res;

    // DFS helper function
    // root  -> current node
    // level -> current depth of the tree (root starts at level 0)
    void dfs(TreeNode* root, int level) {

        // Base case:
        // If the current node is NULL, there is nothing to process
        // So we simply return
        if (root == NULL)
            return;

        // IMPORTANT CONDITION:
        // If level == res.size(), it means:
        // - We are visiting this level for the FIRST time
        // - No node from this level has been added yet
        //
        // Since we traverse RIGHT first,
        // the first node we see at this level is the RIGHTMOST node
        if (level == res.size()) {
            res.push_back(root->val);   // store the rightmost node value
        }

        // Recursive call on the RIGHT child first
        // This ensures right side nodes are visited before left ones
        dfs(root->right, level + 1);

        // Recursive call on the LEFT child
        // Left nodes are visited later and usually ignored
        // because the level is already filled
        dfs(root->left, level + 1);
    }

    // Main function called by LeetCode
    vector<int> rightSideView(TreeNode* root) {

        // Start DFS traversal from the root
        // Initial level is 0 because root is at depth 0
        dfs(root, 0);

        // After DFS is complete, res contains the right side view
        return res;
    }
};
