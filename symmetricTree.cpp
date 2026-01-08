class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Both null → symmetric
        if (t1 == NULL && t2 == NULL)
            return true;

        // One null → not symmetric
        if (t1 == NULL || t2 == NULL)
            return false;

        // Values must match and subtrees must be mirror
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        // Tree is symmetric with itself
        return isMirror(root, root);
    }
};
