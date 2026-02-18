bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set; // Create a set to store unique elements

    // Iterate over each number in the array
    for (int num : nums)
    {
        if (set.count(num))
        {                // Check if num already exists in the set
            return true; // Duplicate found, return true immediately
        }
        set.insert(num); // Otherwise, insert num into the set
    }

    return false; // No duplicates found after checking all elements
}
