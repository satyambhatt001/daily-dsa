int findPeak(vector<int> &nums) {

    // We will use Binary Search to find a "peak" element.
    // A peak is any index i such that:
    // nums[i] >= nums[i-1] AND nums[i] >= nums[i+1]
    //
    // Important trick:
    // In arrays where neighbors are always different OR mountains exist,
    // this binary approach always converges to SOME valid peak.

    // Start pointer at beginning of array
    int start = 0;

    // End pointer at last index of array
    int end = nums.size() - 1;

    // We continue searching while our search space has more than 1 element
    while (start < end) {

        // Avoid potential overflow vs (start + end) / 2
        int mid = start + (end - start) / 2;

        // We compare mid element with the next element (mid + 1)

        // Case 1: nums[mid] > nums[mid + 1]
        // This means we are currently on the "downward slope" of a mountain,
        // OR we are already at a peak region.
        //
        // So the peak must lie on the LEFT side (including mid)
        if (nums[mid] > nums[mid + 1]) {
            end = mid;        // shrink the search range to left half
        }

        // Case 2: nums[mid] < nums[mid + 1]
        // This means we are on an "upward slope".
        //
        // So a peak must lie somewhere to the RIGHT side,
        // because nums[mid+1] is guaranteed to be part of a rising hill.
        else {
            start = mid + 1;  // move to the right half
        }
    }

    // When loop finishes:
    // start == end
    // This position is guaranteed to be a PEAK
    return start;
}
