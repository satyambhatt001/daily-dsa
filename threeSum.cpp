// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<vector<int>> result;
//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i > 0 && nums[i] == nums[i - 1])
//             continue;

//         int left = i + 1;
//         int right = nums.size() - 1;

//         while (left < right)
//         {
//             int sum = nums[i] + nums[left] + nums[right];

//             if (sum == 0)
//             {
//                 result.push_back({nums[i], nums[left], nums[right]});
//                 left++;
//                 right--;

//                 while (left < right && nums[left] == nums[left - 1])
//                 {
//                     left++;
//                 }
//                 while (left < right && nums[right] == nums[right + 1])
//                 {
//                     right--;
//                 }
//             }
//             else if (sum < 0)
//             {
//                 left++;
//             }
//             else
//             {
//                 right--;
//             }
//         }
//     }
//     return result;
// }

vector<vector<int>> threeSum(vector<int> &nums)
{
    // This will store all unique triplets that sum to zero
    vector<vector<int>> result;

    // Sort the array first
    // Sorting helps us:
    // 1. Easily skip duplicates
    // 2. Use two-pointer approach to find pairs efficiently
    sort(nums.begin(), nums.end());

    // Iterate through each number in the array as the first element of triplet
    for (int i = 0; i < nums.size(); i++)
    {
        // Skip duplicate elements to avoid duplicate triplets
        // Example: if nums[i] is same as previous, we already considered it
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Initialize two pointers for the remaining two numbers
        int left = i + 1;           // start right after current element
        int right = nums.size() - 1; // start at the end of array

        // Two-pointer loop: find two numbers such that sum with nums[i] is 0
        while (left < right)
        {
            // Calculate sum of the current triplet
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                // Found a valid triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // Move both pointers to continue searching for other triplets
                left++;
                right--;

                // Skip duplicate elements for left pointer
                // Example: nums[left] == nums[left - 1] means we already considered this number
                while (left < right && nums[left] == nums[left - 1])
                {
                    left++;
                }

                // Skip duplicate elements for right pointer
                while (left < right && nums[right] == nums[right + 1])
                {
                    right--;
                }
            }
            else if (sum < 0)
            {
                // Sum is too small, need a larger number
                // Move left pointer to the right to increase sum
                left++;
            }
            else
            {
                // Sum is too large, need a smaller number
                // Move right pointer to the left to decrease sum
                right--;
            }
        }
    }

    // Return all unique triplets found
    return result;
}


