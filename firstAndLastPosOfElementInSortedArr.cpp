int binarySearch(vector<int>& nums, int target, bool findFirst) {

    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;        // default (not found)

    while (start <= end) {

        int mid = start + (end - start) / 2;

        // Case 1: We found the target
        if (nums[mid] == target) {

            ans = mid;   // store the index

            // If we want FIRST occurrence,
            // move LEFT to see if there's another one
            if (findFirst)
                end = mid - 1;

            // If we want LAST occurrence,
            // move RIGHT to see if there's another one
            else
                start = mid + 1;
        }

        // Case 2: target is greater → go RIGHT
        else if (nums[mid] < target) {
            start = mid + 1;
        }

        // Case 3: target is smaller → go LEFT
        else {
            end = mid - 1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {

    int first = binarySearch(nums, target, true);
    int last  = binarySearch(nums, target, false);

    return {first, last};
}

//2nd approch

vector<int> searchRange(vector<int>& nums, int target) {

    // lower_bound gives iterator to first element >= target
    auto firstIt = lower_bound(nums.begin(), nums.end(), target);

    // If target is NOT found at all
    if (firstIt == nums.end() || *firstIt != target)
        return {-1, -1};

    // upper_bound gives iterator to first element > target
    auto lastIt = upper_bound(nums.begin(), nums.end(), target);

    int first = firstIt - nums.begin();     // convert iterator → index
    int last  = lastIt - nums.begin() - 1;  // previous index

    return {first, last};
}
