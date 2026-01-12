//1st approach O(N)
class Solution {
public:
    // This will store the final zigzag result level by level
    // We use deque so that we can insert from both front and back efficiently
    vector<deque<int>> res;

    // DFS function
    // root  → current node
    // level → depth (or level) of current node in the tree
    void dfs(TreeNode* root, int level) {

        // Base case:
        // If the current node is NULL, there is nothing to process
        if (root == NULL) return;

        // If we are visiting this level for the first time
        // res.size() means how many levels are already created
        // If level == res.size(), this level does not exist yet
        if (level == res.size()) {
            // Create an empty deque for this new level
            res.push_back(deque<int>());
        }

        // Zigzag logic:
        // Even level (0, 2, 4, ...) → left to right
        if (level % 2 == 0) {
            // Insert value at the back of deque
            // Example: [1, 2, 3]
            res[level].push_back(root->val);
        } 
        // Odd level (1, 3, 5, ...) → right to left
        else {
            // Insert value at the front of deque
            // Example: inserting 3 into [4,5] → [3,4,5]
            res[level].push_front(root->val);
        }

        // Recursive call on left child
        // Move to next level (level + 1)
        dfs(root->left, level + 1);

        // Recursive call on right child
        // Move to next level (level + 1)
        dfs(root->right, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Start DFS from root at level 0
        dfs(root, 0);

        // Final answer required is vector<vector<int>>
        vector<vector<int>> ans;

        // Convert each deque into a vector
        for (auto &d : res) {
            // d.begin() to d.end() copies elements of deque into vector
            ans.push_back(vector<int>(d.begin(), d.end()));
        }

        // Return the zigzag level order traversal
        return ans;
    }
};




//2nd approach 


class Solution {
public:
    // This will store the final answer.
    // ans[level] will contain all node values at that level.
    vector<vector<int>> ans;

    // DFS function:
    // root  -> current node we are visiting
    // level -> depth (or level) of the current node in the tree
    void dfs(TreeNode* root, int level) {

        // BASE CASE:
        // If the current node is NULL, there is nothing to process.
        // So we return immediately.
        if (root == NULL)
            return;

        // If we are visiting this level for the first time,
        // then ans does not yet have a vector for this level.
        //
        // Example:
        // level = 2
        // ans.size() = 2
        // This means index 2 does not exist yet.
        if (level == ans.size())
            ans.push_back({});   // create an empty vector for this level

        // ZIGZAG LOGIC:
        //
        // If level is EVEN:
        //   insert values from LEFT to RIGHT
        //
        // If level is ODD:
        //   insert values from RIGHT to LEFT
        //
        // We use level % 2 to check even or odd.

        if (level % 2 == 0) {
            // Even level (0, 2, 4, ...)
            // Normal order: push value at the end
            ans[level].push_back(root->val);
        } else {
            // Odd level (1, 3, 5, ...)
            // Reverse order: insert value at the beginning
            ans[level].insert(ans[level].begin(), root->val);
        }

        // RECURSIVE CALLS:
        //
        // First go to the LEFT child
        // Increase level by 1 because we are going down one level
        dfs(root->left, level + 1);

        // Then go to the RIGHT child
        dfs(root->right, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Start DFS traversal from the root node
        // Root is at level 0
        dfs(root, 0);

        // After DFS completes,
        // ans contains the zigzag level order traversal
        return ans;
    }
};






