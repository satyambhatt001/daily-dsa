int maxProduct(vector<int>& arr) {

    // Number of elements in the array
    int n = arr.size();

    // This will store the final maximum product found
    // Initialized to INT_MIN to handle all-negative arrays
    int ans = INT_MIN;

    // prefix  -> product while scanning from left to right
    // suffix  -> product while scanning from right to left
    int prefix = 1, suffix = 1;

    // Single loop to scan the array from both directions
    for(int i = 0; i < n; i++) {

        // If prefix becomes 0, it means we encountered a zero
        // Zero breaks any product subarray
        // Reset to 1 so a new subarray can start from next element
        if(prefix == 0)
            prefix = 1;

        // Same logic for suffix scan (right to left)
        if(suffix == 0)
            suffix = 1;

        // Multiply current element while moving from left to right
        // This gives product of subarray ending at index i
        prefix = prefix * arr[i];

        // Multiply current element while moving from right to left
        // This gives product of subarray starting at index (n-1-i)
        suffix = suffix * arr[n - 1 - i];

        // Update the answer with the best product seen so far
        // We compare both prefix and suffix because:
        // - prefix handles normal cases
        // - suffix handles cases with odd number of negatives
        ans = max(ans, max(prefix, suffix));
    }

    // Final maximum product subarray
    return ans;
}
