//1st approach
// In this approach, we will use a stack to flatten the binary tree

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);

        if (!s.empty()) {
            curr->right = s.top();
        }
        curr->left = NULL;
    }
}

//2nd approach
// In this approach, we will use recursion to flatten the binary tree
void flatten(TreeNode* root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = NULL;

    TreeNode* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    curr->right = temp;
}

//3rd approach
// In this approach, we will use Morris Traversal to flatten the binary tree
void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* rightmost = curr->left;
            while (rightmost->right) {
                rightmost = rightmost->right;
            }
            rightmost->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
