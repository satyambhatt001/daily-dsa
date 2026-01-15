class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // number of rows in the grid
        int rows = grid.size();

        // number of columns in the grid
        int cols = grid[0].size();

        // queue to perform BFS
        // it will store the positions (row, column) of rotten oranges
        queue<pair<int,int>> q;

        // count of fresh oranges (value = 1)
        int fresh = 0;

        // --------------------------------------------------
        // STEP 1: Traverse the grid
        // --------------------------------------------------
        // - Count how many fresh oranges exist
        // - Push all initially rotten oranges into the queue
        // --------------------------------------------------
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                // if the orange is rotten
                if(grid[i][j] == 2) {
                    // push its position into the queue
                    q.push({i, j});
                }
                // if the orange is fresh
                else if(grid[i][j] == 1) {
                    // increase fresh orange count
                    fresh++;
                }
            }
        }

        // --------------------------------------------------
        // EDGE CASE:
        // If there are no fresh oranges initially,
        // no time is needed
        // --------------------------------------------------
        if(fresh == 0)
            return 0;

        // this variable will store the total time required
        int minutes = 0;

        // --------------------------------------------------
        // Direction arrays for moving:
        // down, up, right, left
        // --------------------------------------------------
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // --------------------------------------------------
        // STEP 2: Multi-source BFS
        // --------------------------------------------------
        // Each level of BFS represents 1 minute
        // --------------------------------------------------
        while(!q.empty()) {

            // number of rotten oranges to process
            // in the current minute
            int size = q.size();

            // flag to check if at least one fresh orange
            // becomes rotten in this minute
            bool rottedThisMinute = false;

            // process all rotten oranges of this level
            for(int i = 0; i < size; i++) {

                // get the front rotten orange position
                auto [x, y] = q.front();
                q.pop();

                // try all 4 directions
                for(int d = 0; d < 4; d++) {

                    // new row index
                    int nx = x + dx[d];

                    // new column index
                    int ny = y + dy[d];

                    // --------------------------------------------------
                    // Check:
                    // 1. within grid bounds
                    // 2. the adjacent cell has a fresh orange
                    // --------------------------------------------------
                    if(nx >= 0 && ny >= 0 &&
                       nx < rows && ny < cols &&
                       grid[nx][ny] == 1) {

                        // make the fresh orange rotten
                        grid[nx][ny] = 2;

                        // decrease fresh orange count
                        fresh--;

                        // push the newly rotten orange
                        // into the queue for next minute
                        q.push({nx, ny});

                        // mark that something rotted this minute
                        rottedThisMinute = true;
                    }
                }
            }

            // --------------------------------------------------
            // Only increase time if at least one orange rotted
            // --------------------------------------------------
            if(rottedThisMinute)
                minutes++;
        }

        // --------------------------------------------------
        // If fresh oranges still remain,
        // it is impossible to rot all oranges
        // --------------------------------------------------
        if(fresh == 0)
            return minutes;
        else
            return -1;
    }
};
