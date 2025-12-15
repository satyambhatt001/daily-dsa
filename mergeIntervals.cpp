#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Step 1: Handle the edge case of empty input
    // If the input vector is empty, there are no intervals to merge, so return an empty vector
    if (intervals.empty())
        return {};

    // Step 2: Sort the intervals based on the starting point of each interval
    // Sorting ensures that if intervals overlap, they will be next to each other
    sort(intervals.begin(), intervals.end());

    // Step 3: Create a vector to store the merged intervals
    vector<vector<int>> merged;

    // Step 4: Push the first interval into the merged vector as a starting point
    merged.push_back(intervals[0]);

    // Step 5: Iterate over the remaining intervals
    for (int i = 1; i < intervals.size(); i++) {
        // merged.back() gives the last interval in the merged vector
        // intervals[i] is the current interval we are examining

        // Step 5a: Check if the current interval overlaps with the last merged interval
        // Overlap condition: start of current interval <= end of last merged interval
        if (intervals[i][0] <= merged.back()[1]) {
            // Step 5b: If there is an overlap, merge them by updating the end of the last merged interval
            // max(merged.back()[1], intervals[i][1]) ensures we take the farthest end point
            merged.back()[1] = max(merged.back()[1], intervals[i][1]); // corrected index from [i] to [1]
        } else {
            // Step 5c: If there is no overlap, just add the current interval to merged
            merged.push_back(intervals[i]);
        }
    }

    // Step 6: Return the merged intervals
    return merged;
}


#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Step 1: Sort intervals by starting time
    sort(intervals.begin(), intervals.end());

    // Step 2: Result vector to store merged intervals
    vector<vector<int>> merged;

    // Step 3: Process each interval
    for (int i = 0; i < intervals.size(); i++) {
        // Take the current interval
        vector<int> interval = intervals[i];

        // If merged is empty OR current interval does not overlap with last merged
        if (merged.empty() || merged.back()[1] < interval[0]) {
            // Add the interval directly
            merged.push_back(interval);
        } else {
            // Overlap case → update the end of last merged interval
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    // Step 4: Return result
    return merged;
}
