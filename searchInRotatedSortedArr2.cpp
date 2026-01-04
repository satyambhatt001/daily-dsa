bool search(vector<int> &nums, int target) {

    // We will do binary search on the rotated sorted array (that may contain duplicates)

    int start = 0;                      // left boundary
    int end   = nums.size() - 1;        // right boundary

    while (start <= end) {              // continue while there is a valid search space

        // Avoid overflow: classic binary search mid formula
        int mid = start + (end - start) / 2;

        // If we directly find the target, return true immediately
        if (nums[mid] == target) {
            return true;
        }

        // --- IMPORTANT PART ---
        // When start, mid and end elements are ALL equal,
        // we CANNOT decide which half is sorted.
        // Example: [2,2,2,3,2]
        //
        // So we simply shrink boundaries by 1 step
        if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
            start++;
            end--;
        }

        // If LEFT HALF is sorted (or at least not rotated)
        else if (nums[start] <= nums[mid]) {

            // Check if target lies inside the sorted LEFT half
            // Range check: [nums[start], nums[mid))
            if (nums[start] <= target && target < nums[mid]) {
                // So discard the RIGHT half
                end = mid - 1;
            } else {
                // Otherwise target must be in the RIGHT half
                start = mid + 1;
            }
        }

        // Otherwise RIGHT HALF must be sorted
        else if (nums[mid] < target && target <= nums[end]) {

            // Target is inside the sorted RIGHT half
            start = mid + 1;
        }

        // Otherwise discard the RIGHT half
        else {
            end = mid - 1;
        }
    }

    // If loop finishes and we didn't find the target — it doesn't exist
    return false;
}
