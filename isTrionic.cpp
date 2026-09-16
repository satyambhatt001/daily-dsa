
class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();
        int i = 1;

        // Phase 1: Increasing
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }

        // We must have at least one increasing step
        if (i == 1) {
            return false;
        }

        // Phase 2: Decreasing
        int decreasingStart = i;

        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }

        // We must have at least one decreasing step
        if (i == decreasingStart || i == n) {
            return false;
        }

        // Phase 3: Increasing again
        int increasingAgainStart = i;

        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }

        // We must have at least one increasing step
        if (i == increasingAgainStart) {
            return false;
        }

        // We must have reached the end
        if (i != n) {
            return false;
        }

        return true;
    }
};
