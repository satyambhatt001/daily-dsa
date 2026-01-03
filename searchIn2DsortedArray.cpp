// We are searching in an array that was originally sorted,
// but then rotated at some pivot (like cutting it and swapping parts).

int search(vector<int>& nums, int target) {

    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {

        // Normal binary search midpoint
        int mid = start + (end - start) / 2;

        // If target found — return index
        if (nums[mid] == target) {
            return mid;
        }

        // ----- STEP 1: Identify which HALF is sorted -----

        // LEFT half is sorted
        if (nums[start] <= nums[mid]) {

            // Check if target lies inside this left sorted half
            if (nums[start] <= target && target < nums[mid]) {

                // Target is in the left half → shrink right boundary
                end = mid - 1;
            } 
            else {
                // Target is NOT in left half → go right
                start = mid + 1;
            }
        }

        // RIGHT half is sorted
        else {

            // Check if target lies inside this right sorted half
            if (nums[mid] < target && target <= nums[end]) {

                // Target is in right half → move left boundary right
                start = mid + 1;
            } 
            else {
                // Target not here → go left
                end = mid - 1;
            }
        }
    }

    // Target not found
    return -1;
}
