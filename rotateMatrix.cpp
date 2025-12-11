// Function to rotate the given n x n matrix by 90 degrees clockwise
// The rotation is done in-place (no extra matrix is used)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Get the size of the matrix (n x n)

    // Step 1: Transpose the matrix
    // Transpose means converting rows into columns.
    // For example:
    // [1 2 3]       [1 4 7]
    // [4 5 6]  -->  [2 5 8]
    // [7 8 9]       [3 6 9]
    //
    // We only swap elements above the diagonal (j > i),
    // otherwise each pair will be swapped twice and cancel out.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    // After transposing, reversing each row will rotate the matrix by 90°.
    // Example after transpose:
    // [1 4 7]    [7 4 1]
    // [2 5 8] -> [8 5 2]
    // [3 6 9]    [9 6 3]
    //
    // Which is the final rotated matrix.
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
