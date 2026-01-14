class Solution {
public:

    // This function performs DFS starting from cell (i, j)
    // It returns the area (number of connected land cells) of the island
    int dfs(vector<vector<int>>& grid, int i, int j) {

        // --------------------------------------------------
        // STEP 1: Boundary and base condition checks
        // --------------------------------------------------

        // If row index goes out of grid bounds
        if (i < 0)
            return 0;

        // If column index goes out of grid bounds
        if (j < 0)
            return 0;

        // If row index exceeds grid size
        if (i >= grid.size())
            return 0;

        // If column index exceeds grid width
        if (j >= grid[0].size())
            return 0;

        // If current cell is water (0), no area contributed
        if (grid[i][j] == 0)
            return 0;

        // --------------------------------------------------
        // STEP 2: Mark current land as visited
        // --------------------------------------------------

        // We change land (1) to water (0)
        // This ensures we do NOT visit the same cell again
        grid[i][j] = 0;

        // --------------------------------------------------
        // STEP 3: Count current cell
        // --------------------------------------------------

        // Since this cell is land, it contributes 1 to area
        int area = 1;

        // --------------------------------------------------
        // STEP 4: Explore all 4 possible directions
        // --------------------------------------------------

        // Explore downward cell
        area += dfs(grid, i + 1, j);

        // Explore upward cell
        area += dfs(grid, i - 1, j);

        // Explore right cell
        area += dfs(grid, i, j + 1);

        // Explore left cell
        area += dfs(grid, i, j - 1);

        // --------------------------------------------------
        // STEP 5: Return total area of this island
        // --------------------------------------------------

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        // This variable will store the maximum island area found
        int maxArea = 0;

        // --------------------------------------------------
        // STEP 6: Traverse every cell in the grid
        // --------------------------------------------------

        // Loop through each row
        for (int i = 0; i < grid.size(); i++) {

            // Loop through each column
            for (int j = 0; j < grid[0].size(); j++) {

                // --------------------------------------------------
                // STEP 7: Start DFS when land is found
                // --------------------------------------------------

                // If current cell is land (1),
                // it means a new island starts here
                if (grid[i][j] == 1) {

                    // Perform DFS to calculate area of this island
                    int currentIslandArea = dfs(grid, i, j);

                    // Update maximum area if current is larger
                    maxArea = max(maxArea, currentIslandArea);
                }
            }
        }

        // --------------------------------------------------
        // STEP 8: Return the maximum island area
        // --------------------------------------------------

        return maxArea;
    }
};
