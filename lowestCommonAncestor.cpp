class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // -------------------------------
        // BASE CASE
        // -------------------------------
        // If the current node is NULL, it means we reached
        // the end of a path without finding LCA
        if (root == NULL)
            return NULL;

        // -------------------------------
        // CASE 1: BOTH p AND q ARE SMALLER THAN root
        // -------------------------------
        // Since this is a BST:
        // - If both values are smaller than root->val,
        //   then both nodes MUST lie in the LEFT subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // -------------------------------
        // CASE 2: BOTH p AND q ARE GREATER THAN root
        // -------------------------------
        // Again using BST property:
        // - If both values are greater than root->val,
        //   then both nodes MUST lie in the RIGHT subtree
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // -------------------------------
        // CASE 3: SPLIT POINT (THIS IS THE ANSWER)
        // -------------------------------
        // If we reach here, it means:
        // - Either p is on the left and q is on the right
        // - OR one of them is equal to root
        //
        // This node is the FIRST node where paths diverge,
        // so this node is the Lowest Common Ancestor (LCA)
        return root;
    }
};
