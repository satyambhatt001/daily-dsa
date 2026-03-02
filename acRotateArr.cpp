#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Reverse entire matrix (top row ↔ bottom row)
        reverse(matrix.begin(), matrix.end());

        // Step 2: Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
