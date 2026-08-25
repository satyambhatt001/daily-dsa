class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ans = min(ans, nums[i]);
        }

        return ans;
    }
};

//2nd approach
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in the right half
                low = mid + 1;
            }
            else {
                // Minimum is at mid or in the left half
                high = mid;
            }
        }

        return nums[low];
    }
};
