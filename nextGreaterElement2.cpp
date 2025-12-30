vector<int> nextGreater(vector<int> &nums) {

    int n = nums.size();

    // This will store the answer
    // res[i] = next greater element of nums[i]
    // Initialize all with -1 (default answer if no greater element exists)
    vector<int> res(n, -1);

    // Monotonic stack (will store INDEXES, not values)
    stack<int> st;

    // We iterate from (2*n - 1) → 0
    // because the array is CIRCULAR
    // We simulate 2 passes over the array
    for (int i = 2 * n - 1; i >= 0; i--) {

        // Map i back into 0…n-1 (circular behavior)
        int idx = i % n;

        // While stack is NOT empty AND
        // current element is GREATER than the element at stack top
        //
        // Pop because the stack’s top cannot be "next greater"
        // for any element to its left anymore
        while (!st.empty() && nums[st.top()] <= nums[idx]) {
            st.pop();
        }

        // During the FIRST PASS ONLY (i < n)
        // We should start assigning answers
        //
        // Before pushing current index,
        // whatever is on stack top is the next greater element
        if (i < n) {

            // If stack empty → no greater element
            if (!st.empty()) {
                res[idx] = nums[st.top()];
            }
        }

        // Push current index to stack
        // Because it may serve as "next greater" for future elements
        st.push(idx);
    }

    return res;
}
