vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    // This map will store:
    // key   -> number from nums2
    // value -> its next greater element (or -1 if none exists)
    unordered_map<int,int> nextGreater;

    // Monotonic stack (will store elements in decreasing order)
    // The TOP of the stack will always be the "next greater candidate"
    stack<int> st;

    // We traverse nums2 from RIGHT to LEFT
    // Because "next greater" means: look to the RIGHT side of a number
    for (int i = nums2.size() - 1; i >= 0; i--) {

        int num = nums2[i];   // current number we are processing

        // Remove (pop) all elements that are
        // smaller than OR equal to current number
        //
        // Why?
        // Because they can NEVER be "next greater"
        // for this number or for any number to its left.
        while (!st.empty() && st.top() <= num) {
            st.pop();
        }

        // Now, if stack is empty -> nothing greater on the right
        if (st.empty()) {
            nextGreater[num] = -1;
        }
        else {
            // Top of stack is the first greater element to the right
            nextGreater[num] = st.top();
        }

        // Push current number into stack
        // It may become the "next greater" for elements to its left
        st.push(num);
    }

    // Result vector (for nums1 order)
    vector<int> res;

    // For every number in nums1, just fetch the precomputed answer
    // from our map
    for (int num : nums1) {
        res.push_back(nextGreater[num]);
    }

    // Return final output
    return res;
}
