// We are searching a value inside a 2D matrix using Binary Search.
// Matrix has the following properties:
// 1) Each row is sorted.
// 2) The first element of a row is greater than the last of previous row.
// So — we can pretend the 2D matrix is actually ONE big sorted array.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    // If the matrix has no rows OR the first row has no columns -> nothing to search
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    // Total number of rows
    int row = matrix.size();

    // Total number of columns
    int cols = matrix[0].size();

    // We treat the matrix like a single 1D array:
    // Start index = 0
    int start = 0;

    // End index = total elements - 1
    int end = row * cols - 1;

    // Standard binary search loop
    while (start <= end) {

        // Prevents overflow compared to (start + end) / 2
        int mid = start + (end - start) / 2;

        // Convert mid index (1D) back to 2D coordinates:
        //   Row index = mid / cols
        //   Column index = mid % cols
        int midValue = matrix[mid / cols][mid % cols];

        // If we found the target
        if (midValue == target) {
            return true;
        }

        // If target is larger, ignore left half
        else if (midValue < target) {
            start = mid + 1;
        }

        // If target is smaller, ignore right half
        else {
            end = mid - 1;
        }
    }

    // If loop finishes, value was not found
    return false;
}



// 2nd approach bruteforce

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    // If matrix has no rows or no columns
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    // Loop through every row
    for (int i = 0; i < matrix.size(); i++) {

        // Loop through every column in current row
        for (int j = 0; j < matrix[i].size(); j++) {

            // Check if current element equals target
            if (matrix[i][j] == target) {
                return true;   // Found it!
            }
        }
    }

    // If we reach here → target was not present
    return false;
}
