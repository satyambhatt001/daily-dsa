// 1st approach bruteforce O(n^2)

// Function to calculate the height of a binary tree
int height(TreeNode* root) {

    // BASE CASE:
    // If the current node is NULL, it means:
    // - Tree is empty OR
    // - We have gone past a leaf node
    // Height of an empty tree is 0
    if(root == NULL)
        return 0;

    // RECURSIVE CASE:
    // 1. Find height of left subtree
    // 2. Find height of right subtree
    // 3. Take the maximum of both
    // 4. Add 1 for the current node
    //
    // Why +1?
    // Because height is counted as number of nodes
    // from current node to the deepest leaf
    return 1 + max(
        height(root->left),   // height of left subtree
        height(root->right)   // height of right subtree
    );
}

// Function to check if a binary tree is height-balanced
bool isBalanced(TreeNode* root) {

    // BASE CASE:
    // An empty tree is always balanced
    if(root == NULL)
        return true;

    // Step 1:
    // Calculate height of left subtree
    int lh = height(root->left);

    // Step 2:
    // Calculate height of right subtree
    int rh = height(root->right);

    // Step 3:
    // Check the balance condition at current node
    // A tree is balanced if:
    // |height(left) - height(right)| <= 1
    if(abs(lh - rh) > 1)
        return false;  // Current node is unbalanced

    // Step 4:
    // Even if current node is balanced,
    // we must check balance of:
    // - left subtree
    // - right subtree
    //
    // If either subtree is unbalanced,
    // the whole tree is unbalanced
    return isBalanced(root->left)   // check left subtree
        && isBalanced(root->right); // check right subtree
}



// 2nd approach optimal solution O(n)



// This function does TWO jobs at the same time:
// 1 Calculates the height of the tree
// 2 Checks whether the tree is balanced
//
// IMPORTANT IDEA:
// - If the tree is balanced → return its height
// - If the tree is NOT balanced → return -1
//
// Returning -1 is a SIGNAL that imbalance is detected
int height(TreeNode* root) {

    // BASE CASE:
    // If the node is NULL, it means:
    // - tree is empty OR
    // - we reached past a leaf
    // Height of an empty tree is 0
    if(root == NULL)
        return 0;

    // Step 1:
    // Recursively find height of left subtree
    int lh = height(root->left);

    // If left subtree already returned -1,
    // it means left subtree is NOT balanced
    // So we immediately return -1 without
    // checking anything else (early exit)
    if(lh == -1)
        return -1;

    // Step 2:
    // Recursively find height of right subtree
    int rh = height(root->right);

    // If right subtree already returned -1,
    // it means right subtree is NOT balanced
    // So we immediately return -1
    if(rh == -1)
        return -1;

    // Step 3:
    // Check balance condition at CURRENT node
    // If height difference is more than 1,
    // then this subtree is NOT balanced
    if(abs(lh - rh) > 1)
        return -1;

    // Step 4:
    // If current node is balanced,
    // return height of current subtree
    //
    // Height = 1 (current node)
    //          + max height of left/right subtree
    return 1 + max(lh, rh);
}

// This function simply checks the result of height()
bool isBalanced(TreeNode* root) {

    // If height() returns -1 → tree is NOT balanced
    // If height() returns >= 0 → tree IS balanced
    return height(root) != -1;
}

