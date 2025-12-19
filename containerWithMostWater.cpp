// Function to calculate the maximum area of water a container can hold
// using the "Two Pointer" technique
int maxArea(vector<int> &height)
{
    // Initialize two pointers:
    // 'left' starts at the beginning of the array (index 0)
    // 'right' starts at the end of the array (last index)
    int left = 0;
    int right = height.size() - 1;

    // Variable to store the maximum area found so far
    int maxArea = 0;

    // Run the loop until the two pointers meet
    while (left < right)
    {
        // Step 1: Find the height of the container.
        // The height of water is determined by the shorter line,
        // because water would spill over the shorter one.
        int h = min(height[left], height[right]);

        // Step 2: Find the width of the container.
        // Width = distance between left and right pointers.
        int width = right - left;

        // Step 3: Calculate the area = height * width.
        // Then update maxArea if the current area is larger.
        maxArea = max(maxArea, h * width);

        // Step 4: Move the pointer that is at the shorter line.
        // Why? Because the area is limited by the shorter line.
        // If we move the taller line inward, width decreases,
        // but height does not increase (still limited by shorter line).
        // So, to possibly find a bigger container,
        // we move the shorter line inward.
        if (height[left] < height[right])
        {
            left++;   // Move left pointer to the right
        }
        else
        {
            right--;  // Move right pointer to the left
        }
    }

    // After checking all possible pairs, return the maximum area found
    return maxArea;
}
