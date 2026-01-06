//1st approach bruteforce

  int search(vector<int>& nums, int target) {
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(mini>nums[i]){
                mini=nums[i];
            }
        }
        return mini;
    }



//2nd approach binary Search



int findMin(vector<int>& nums) {

    // start pointer (beginning of array)
    int start = 0;

    // end pointer (last index of array)
    int end = nums.size() - 1;


    // We keep searching while start is strictly less than end.
    // When start == end, it means both are pointing to the same element,
    // and that element will be the minimum.
    while(start < end) {

        // Calculate the middle index in a safe way
        // (avoids overflow compared to (start + end) / 2)
        int mid = start + (end - start) / 2;


        // -------------------------------------------------------
        // IMPORTANT COMPARISON:
        // Compare element at mid with element at end
        // -------------------------------------------------------

        // CASE 1:
        // If nums[mid] is greater than nums[end],
        // it means the rotation point (and therefore the minimum)
        // lies on the RIGHT side of 'mid'.
        //
        // Example: [4,5,6,7,0,1,2]
        //           s     m     e
        // nums[mid] = 7 , nums[end] = 2
        //
        // Since left side is sorted and mid is big,
        // the small values must be on the right side.
        if(nums[mid] > nums[end]) {

            // So we discard the LEFT half INCLUDING mid,
            // and move start to mid + 1.
            start = mid + 1;
        }

        // CASE 2:
        // Otherwise nums[mid] <= nums[end]
        //
        // That means the right side is sorted,
        // AND the minimum is either:
        //  • at mid
        //  • or somewhere to the LEFT of mid
        //
        // Example: [4,5,6,7,0,1,2]
        //                 m   e
        // nums[mid] = 0, nums[end] = 2 → mid may be min,
        // so we KEEP mid in the range.
        else {

            // Move end to mid (NOT mid - 1),
            // because mid could still be the answer.
            end = mid;
        }
    }

    // When loop ends:
    // start == end
    //
    // Both pointers are pointing to the minimum element.
    return nums[start];
}

