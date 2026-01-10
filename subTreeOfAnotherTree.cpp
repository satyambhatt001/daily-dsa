class Solution {
public:
    // Check if two trees are exactly the same
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL)
            return true;

        if (a == NULL || b == NULL)
            return false;

        if (a->val != b->val)
            return false;

        return isSameTree(a->left, b->left) &&
               isSameTree(a->right, b->right);
    }

    // Check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
