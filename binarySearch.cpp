// Function to perform Binary Search on a sorted array
// Returns the index of target if found, otherwise returns -1
int binarySearch(vector<int>& arr, int target) {

    // start -> points to the first index of the array
    int start = 0;

    // end -> points to the last index of the array
    int end = arr.size() - 1;

    // We keep searching as long as our search space is valid
    // (i.e., start has not crossed end)
    while (start <= end) {

        // mid is the middle index of current search range
        // We use: start + (end - start)/2
        // instead of: (start + end)/2
        // to avoid integer overflow for large values
        int mid = start + (end - start) / 2;

        // If the element at mid is exactly our target,
        // we return mid (its position)
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater than the middle element,
        // then target must lie in the RIGHT half
        // so we move start to mid + 1
        else if (arr[mid] < target) {
            start = mid + 1;
        }

        // Otherwise, target must be in the LEFT half,
        // so we move end to mid - 1
        else {
            end = mid - 1;
        }
    }

    // If we reach here, it means target was not found
    return -1;
}
