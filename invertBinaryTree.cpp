class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;

        // Swap left and right subtrees
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert children
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
